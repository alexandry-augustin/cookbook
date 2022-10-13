#include <iostream>
#include <string>
#include <cstring>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
//---------------------------------------------------------
enum { max_length = 3 };
//---------------------------------------------------------
void handle_send_to(
	boost::asio::ip::udp::socket* socket,
	boost::asio::ip::udp::endpoint* endpoint,
	char* data,
	const boost::system::error_code& ec,
	size_t bytes_sent)
{
	std::cout<<"[TX] [ec:"<<ec.message()<<"] [bytes_transferred:"<<bytes_sent<<"]"<<std::endl;
}
//---------------------------------------------------------
void handle_receive_from(boost::asio::ip::udp::socket* socket,
	boost::asio::ip::udp::endpoint* endpoint,
	char* data,
	const boost::system::error_code& ec,
	size_t bytes_recvd)
{
	std::cout<<"[RX] [ec:"<<ec.message()<<"] [bytes_received:"<<bytes_recvd<<"]"<<std::endl;

	socket->async_receive_from(
		boost::asio::buffer(data, max_length),
		*endpoint,
		boost::bind(handle_receive_from,
			socket,
			endpoint,
			data,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));

	strcpy(data, "pong");
	socket->async_send_to(
			boost::asio::buffer(data, 4),
			*endpoint,
			boost::bind(handle_send_to,
				socket,
				endpoint,
				data,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
}
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service; 
		boost::asio::ip::udp::socket*	socket=NULL;
		boost::asio::ip::udp::endpoint*	endpoint=new boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 4025);

		//socket=new boost::asio::ip::udp::socket(io_service);
		//socket->open(boost::asio::ip::udp::v4());
		//socket->bind(*endpoint);
		//or
		socket=new boost::asio::ip::udp::socket(io_service, *endpoint);

		char data[max_length];

		//async
		socket->async_receive_from(
			boost::asio::buffer(data, max_length),
			*endpoint,
			boost::bind(handle_receive_from,
				socket,
				endpoint,
				data,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));

		try
		{
			io_service.run();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << "\n";
		}
		/*
		//sync
		while(true)
		{
			int bytes=socket->receive_from(boost::asio::buffer(data), *endpoint);
			std::string msg(data, bytes);
			std::string str("pong");
			socket->send_to(boost::asio::buffer(str), *endpoint);
		}*/
	}
	return 0;
}
