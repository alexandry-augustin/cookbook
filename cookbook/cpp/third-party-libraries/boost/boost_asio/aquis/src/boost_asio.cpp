#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
void handle_00(boost::asio::io_service& io_service)
{
	static int n=0;
	std::cout << "test\n";
	if(n++<5)
		io_service.post(boost::bind(handle_00, boost::ref(io_service)));
}
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service; 

		io_service.post(boost::bind(handle_00, boost::ref(io_service)));
		io_service.run();
	}
	return 0;
}
