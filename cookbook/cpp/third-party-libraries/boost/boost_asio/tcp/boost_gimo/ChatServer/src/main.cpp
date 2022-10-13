#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <gimo/BaseConfiguration.h>
#include <gimo/BaseException.h>
#include "ChatServer.h"

BaseConfiguration config("config_chat_server.ini");

int main(int argc, char* argv[])
{
	try
	{
		switch(argc)
		{
		case 2:
			config.set("Common", "TCPport", atoi(argv[1]));
		case 1:
			break;
		default:
			throw BaseException("incorrect number of arguments");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr<<"[main] Exception: "<<e.what()<<"."<<std::endl;
		std::cout<<"usage: ChatServer [hostIP]"<<std::endl;
		return 1; //failure
	}
	
	try
	{
		std::cout<<config.str()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<<"[main] Exception: "<<e.what()<<"."<<std::endl;
		return 1; //failure
	}	
	
	try
	{
		int tcpPort=config.get<int>("Common", "TCPport");
	 	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), tcpPort);
		ChatServer chatServer(endpoint);
		chatServer.accept(); //async
		
		chatServer.run();
	}
	catch(const std::exception& e)
	{
		std::cerr<<"[main] Exception: "<<e.what()<<std::endl;
	}
	
	return 0; //success
}
