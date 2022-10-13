#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service; 
		boost::asio::ip::tcp::acceptor*	acceptor;
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), 4025);
		
		acceptor=new boost::asio::ip::tcp::acceptor(io_service);
		try
		{
			acceptor->open(endpoint.protocol());
			acceptor->set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
			acceptor->bind(endpoint);
			acceptor->listen();
		}
		catch(const boost::system::system_error& e)
		{
			assert(false);
		}
		delete acceptor;
	
		acceptor=new boost::asio::ip::tcp::acceptor(io_service, endpoint);
		delete acceptor;

	}
	{
		const int			port=50013;
		boost::asio::io_service		io_service;
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), port);
		boost::asio::ip::tcp::acceptor	acceptor(io_service, endpoint);
		boost::asio::ip::tcp::socket	socket(io_service);
		std::ostringstream		oss;
		std::string			sep("_end_");
		
		std::cout<<"listening on ["
			<<endpoint.address().to_string()<<":"<<endpoint.port()<<"]..."<<std::endl;
		acceptor.accept(socket);
	
		for(int i=1;i<10;++i)
		{
			oss.str(std::string(""));
			oss<<std::string(i, '*')<<"_end_";
			boost::asio::write(socket, boost::asio::buffer(oss.str()));
			//socket.write_some(boost::asio::buffer(message));
			std::cout<<"["<<oss.str()<<"]"<<std::endl;
			boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		}

		socket.close();
	}
	return 0;
}
