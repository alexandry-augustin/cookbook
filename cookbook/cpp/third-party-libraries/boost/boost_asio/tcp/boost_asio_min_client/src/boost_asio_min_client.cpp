#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/regex.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
void pass(const boost::system::error_code& ec, std::size_t bytes_transferred)
{
	std::cout<<"[ec:"<<ec.message()<<"] [bytes_transferred:"<<bytes_transferred<<"]"<<std::endl;
}
//---------------------------------------------------------
int main()
{
	{
		//const char*			host="10.1.10.69";
		//const int			port=500;
		const char*			host="127.0.0.1";
		const int			port=50013;
		boost::asio::io_service		io_service;
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address::from_string(host), port);
		boost::asio::ip::tcp::socket	socket(io_service);
		boost::system::error_code 	ec;
		boost::asio::streambuf		streambuf;
		boost::regex			regex("_end_");
		std::size_t			bytes_transferred;
		std::string			message("hi_end_");
	
		std::cout<<"connecting to ["
			<<endpoint.address().to_string()<<":"<<endpoint.port()<<"]..."<<std::endl;
		socket.connect(endpoint, ec);
		if(ec.value()!=boost::system::errc::success)
		{
			std::cerr<<ec.message()<<std::endl;
			return 1;
		}

		//boost::asio::async_write(socket, boost::asio::buffer(message), boost::bind(pass, _1, _2));
		//boost::asio::write(socket, boost::asio::buffer(message));
		while(true)
		{
			bytes_transferred=boost::asio::read_until(socket, streambuf, regex);
			
			boost::asio::streambuf::const_buffers_type const_buffers(streambuf.data());
			//assert(streambuf.size()!=bytes_transferred);
			std::string read_str(boost::asio::buffers_begin(const_buffers), boost::asio::buffers_begin(const_buffers)+bytes_transferred);
		
			//std::ostringstream oss;
			//oss<<&streambuf;
			//oss.write(&streambuf, bytes_transferred);
	
			std::cout<<"[data:"<<read_str<<"] [bytes_received:"<<bytes_transferred<<"] [streambuf::size:"<<streambuf.size()<<"]"<<std::endl;
			streambuf.consume(bytes_transferred);
		}
		io_service.run();
	}
	return 0;
}
