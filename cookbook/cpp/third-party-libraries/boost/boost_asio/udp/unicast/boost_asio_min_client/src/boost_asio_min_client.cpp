#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
//---------------------------------------------------------
enum { max_length = 1024 };
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	try
	{
		boost::asio::io_service io_service;
		boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::udp::v4(), 0);
		boost::asio::ip::udp::socket socket(io_service, endpoint);

		//boost::asio::ip::udp::resolver resolver(io_service);
		//boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "127.0.0.1", "4025");
		//boost::asio::ip::udp::resolver::iterator iterator = resolver.resolve(query);
		boost::asio::ip::udp::endpoint	remote_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 4025);

		std::string request("ping");
		std::cout<<"[TX] "<<request<<"\n";
		//socket.send_to(boost::asio::buffer(request), *iterator);
		socket.send_to(boost::asio::buffer(request), remote_endpoint);

		char reply[max_length];
		boost::asio::ip::udp::endpoint sender_endpoint;
		size_t reply_length = socket.receive_from(boost::asio::buffer(reply, max_length), sender_endpoint);

		std::cout<<"[RX] ";
		std::cout.write(reply, reply_length);
		std::cout<<"\n";
	}
	catch (std::exception& e)
	{
		std::cerr<<"Exception: "<<e.what()<<"\n";
		return 1;
	}
	return 0;
}
