#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//--------------------------------------------------
int main()
{
	{
		boost::asio::io_service				io_service;
		boost::asio::ip::tcp::endpoint			endpoint;
		boost::asio::ip::tcp::resolver			resolver(io_service);
		boost::asio::ip::tcp::resolver::query		query("www.google.com", "80");
		boost::asio::ip::tcp::resolver::iterator	it;
		boost::asio::ip::tcp::resolver::iterator	end;
		
		it=resolver.resolve(query);
		while(it++ != end)
		{
			endpoint=*it;
	
			std::cout<<endpoint.address().to_string()<<std::endl;
			std::cout<<endpoint.port()<<std::endl;
			//std::cout<<endpoint.protocol()<<std::endl;
		}
	}
	return 0;
}
