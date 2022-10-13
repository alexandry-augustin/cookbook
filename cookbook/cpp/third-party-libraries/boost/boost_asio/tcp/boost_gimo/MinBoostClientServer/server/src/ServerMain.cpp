#include <iostream>
#include <string>
#include <boost/asio.hpp>

int main()
{
	try
	{
		const int port=50013;
		boost::asio::io_service		io_service;
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), port);
		boost::asio::ip::tcp::acceptor	acceptor(io_service, endpoint);
		boost::asio::ip::tcp::socket	socket(io_service);
		
		std::cout<<"Server listening on port ["<<port<<"]..."<<std::endl;
		acceptor.accept(socket); //blocking
		std::string message("ping ping ping\n");
		boost::asio::write(socket, boost::asio::buffer(message));
		//or
		//socket.write_some(boost::asio::buffer(message));
		socket.close();
	}
	catch(std::exception& e)
	{
		std::cerr<<"Exception: "<<e.what()<<std::endl;
	}
}
