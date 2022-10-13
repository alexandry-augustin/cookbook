#ifndef BASE_IO_SERVICE_IMPLEMENTATION_H
#define BASE_IO_SERVICE_IMPLEMENTATION_H

#include <boost/asio.hpp> 
#include <cstddef> 

class base_io_service_implementation 
{ 
public: 
	base_io_service_implementation() 
	{ 
	} 
	~base_io_service_implementation() 
	{ 
	} 
	void destroy() 
	{ 
	} 
	void sync_print(std::string str, boost::system::error_code& e) 
	{
		//e=boost::asio::error::operation_aborted; 
		//e=boost::system::error_code(); 
		std::cout<<"sdcss"<<std::endl;
	} 
};

#endif
