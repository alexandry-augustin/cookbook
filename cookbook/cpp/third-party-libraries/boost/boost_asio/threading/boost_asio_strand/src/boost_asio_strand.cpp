#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service; 
		boost::asio::deadline_timer	timer(io_service);
		boost::asio::io_service::strand	strand(io_service);
	
		timer.expires_from_now(boost::posix_time::milliseconds(1000));
		//timer.async_wait(boost::bind(print, "timedout"));
		//strand.post(boost::bind(print, "posted"));
		//strand.dispatch(boost::bind(print, "dispatched"));

		io_service.run();
	}
	{
	}
	return 0;
}
