#include <iostream>
#include <sstream>
#include <string>
#include <boost/asio.hpp>
#include "boost/bind.hpp"
#include "boost/date_time/posix_time/posix_time_types.hpp"
//---------------------------------------------------------
const short multicast_port = 30001;
//---------------------------------------------------------
class sender
{
	boost::asio::ip::udp::endpoint	_endpoint;
	boost::asio::ip::udp::socket	_socket;
	boost::asio::deadline_timer	_timer;
	int				_n;
	std::string			_buf;
public:
	sender(boost::asio::io_service& io_service, const boost::asio::ip::address& multicast_address):
		_endpoint(multicast_address, multicast_port),
		_socket(io_service, _endpoint.protocol()),
		_timer(io_service),
		_n(0)
	{
		std::ostringstream os;
		os << "Message " << _n++;
		_buf = os.str();

		_socket.async_send_to(boost::asio::buffer(_buf), _endpoint,
			boost::bind(&sender::handle_send_to, this, boost::asio::placeholders::error));
	}
	void handle_send_to(const boost::system::error_code& error)
	{
		assert(!error);
		std::cout<<"[TX] "<<_buf<<std::endl;
		_timer.expires_from_now(boost::posix_time::seconds(1));
		_timer.async_wait(boost::bind(&sender::handle_timeout, this, boost::asio::placeholders::error));
	}
	void handle_timeout(const boost::system::error_code& error)
	{
		assert(!error);
		std::ostringstream os;
		os << "Message " << _n++;
		_buf = os.str();

		_socket.async_send_to(boost::asio::buffer(_buf), _endpoint,
			boost::bind(&sender::handle_send_to, this, boost::asio::placeholders::error));
	}
};
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_service io_service;
		sender s(io_service, boost::asio::ip::address::from_string("239.255.0.1"));
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
