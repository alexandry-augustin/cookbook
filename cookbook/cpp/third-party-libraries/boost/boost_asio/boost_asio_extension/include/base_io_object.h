#ifndef BASE_IO_OBJECT_H
#define BASE_IO_OBJECT_H

#include <boost/asio.hpp> 
#include <cstddef> 

template <typename Service>
class base_io_object:
	public boost::asio::basic_io_object<Service> 
{ 
public: 
	explicit base_io_object(boost::asio::io_service& io_service):
		boost::asio::basic_io_object<Service>(io_service)
	{ 
	} 
	void sync_print(std::string str) 
	{ 
//		get_service().sync_print(get_implementation(), str); 
		std::cout<<"00000"<<std::endl;
	} 
	template <typename Handler> 
	void async_print(std::string str, Handler handler) 
	{ 
		//get_service().async_print(get_implementation(), str, handler); 
		std::cout<<"1111"<<std::endl;
	} 
};

#endif
