#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "boost/bind.hpp"
//---------------------------------------------------------
const short multicast_port = 30001;
//---------------------------------------------------------
class receiver
{
	boost::asio::ip::udp::socket	_socket;
	boost::asio::ip::udp::endpoint	_endpoint;
	enum { max_length = 1024 };
	char data_[max_length];
public:
	receiver(boost::asio::io_service& io_service,
			const boost::asio::ip::address& listen_address,
			const boost::asio::ip::address& multicast_address)
		: _socket(io_service)
	{
		// Create the socket so that multiple may be bound to the same address.
		boost::asio::ip::udp::endpoint listen_endpoint(listen_address, multicast_port);
		_socket.open(listen_endpoint.protocol());
		//or
		//_socket.open(boost::asio::ip::udp::v4());
		_socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
		_socket.bind(listen_endpoint);

		// Join the multicast group.
		_socket.set_option(boost::asio::ip::multicast::join_group(multicast_address));

		_socket.async_receive_from(boost::asio::buffer(data_, max_length), _endpoint,
			boost::bind(&receiver::handle_receive_from, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	void handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd)
	{
		assert(!error);
		std::cout << "[RX] ";
		std::cout.write(data_, bytes_recvd);
		std::cout << std::endl;

		_socket.async_receive_from(boost::asio::buffer(data_, max_length), _endpoint,
			boost::bind(&receiver::handle_receive_from, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}
};
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_service io_service;
		receiver r(io_service,
			boost::asio::ip::address::from_string("0.0.0.0"),
			boost::asio::ip::address::from_string("239.255.0.1"));
		io_service.run();
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
