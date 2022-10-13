#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "base_io_object.h"
#include "base_io_service.h"
#include "base_io_service_implementation.h"

typedef base_io_object<base_io_service<base_io_service_implementation> > base_io_object_;

void handler(const boost::system::error_code& e) 
{
	assert(false);
	std::cout<<"."<<std::endl; 
}

int main()
{
	{
		boost::asio::io_service		io_service; 
		boost::asio::io_service::work	work(io_service);
		base_io_object_ b(io_service); 
		
		b.async_print("hi", handler);
		b.sync_print("hi");
		io_service.run();
	}
	
	return 0;
}
