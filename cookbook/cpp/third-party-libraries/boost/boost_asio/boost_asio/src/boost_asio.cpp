#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
//const boost::system::error_code& e
//---------------------------------------------------------
static int N;
void setN(int n)
{
	N=n;
}
//---------------------------------------------------------
void pass()
{
}
//---------------------------------------------------------
void sleep_(int n)
{
	boost::this_thread::sleep(boost::posix_time::seconds(n));
}
//---------------------------------------------------------
void print_int(int i) 
{
	std::cout<<i<<std::endl; 
}
//---------------------------------------------------------
void print(std::string str) 
{
	std::cout<<str<<std::endl; 
}
//---------------------------------------------------------
void handle_timeout(const boost::system::error_code& e) 
{
	std::cout<<"timedout"<<std::endl; 
}
//---------------------------------------------------------
void handle_timeout(boost::asio::deadline_timer* timer, const boost::system::error_code& e)
{
	std::cout<<"."<<std::flush;

// 	reset:
//	timer->expires_from_now(boost::posix_time::seconds(1));
//	timer->async_wait(boost::bind(handle_timeout, timer, _1));
}
//---------------------------------------------------------
void handle_00()
{
	throw int(0);
}
//---------------------------------------------------------
// io_service:
// 	run poll run_one poll_one stop
// 	post dispatch wrap
// 	reset
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service;
	
		N=1;
		assert(N==1);
		io_service.post(boost::bind(setN, 2));
		assert(N==1);
		io_service.poll_one();
		assert(N==2);
	}
	{
		boost::asio::io_service		io_service;
		boost::function<void (void)>	run;
		
		io_service.post(pass);
		run=boost::bind(&boost::asio::io_service::run, &io_service);
		run();
	}
	{
		boost::asio::io_service		io_service;
		boost::asio::deadline_timer	timer(io_service);
		
		timer.expires_from_now(boost::posix_time::milliseconds(1000));
		timer.async_wait(boost::bind(pass));

		//io_service.post(boost::bind(sleep_, 1000));
		//io_service.post(pass);
		//io_service.post(boost::bind(print, 0));
	
		//io_service.poll(); //run all ready operations then exit
		//io_service.run(); //run all ready and pending operations then exit
		
		//io_service.poll_one(); //run one ready operation then exit
		io_service.run_one(); //run one ready operation or block until one pending operation is ready then exit
	}
	{
		boost::asio::io_service		io_service;
		
		//io_service.wrap(boost::bind(sleep_, 5));
		io_service.dispatch(boost::bind(sleep_, 5));
		//io_service.post(boost::bind(sleep_, 5)); //always return immediatly
	
		//io_service.run();
	}
	{
		boost::asio::io_service		io_service;
		boost::asio::deadline_timer	timer(io_service);

		timer.expires_from_now(boost::posix_time::milliseconds(1000));
		timer.async_wait(boost::bind(print_int, 3));

		for(int i=0; i<3; ++i)
			io_service.post(boost::bind(print_int, i));

		io_service.run();
	}
	{
		boost::asio::io_service		io_service; 
		//boost::asio::io_service::work will simulate a pending operation that never completes
		boost::asio::io_service::work	work(io_service);

		io_service.poll();
	}
	{
		boost::asio::io_service		io_service; 
		boost::shared_ptr<boost::asio::io_service::work> work_ptr(new boost::asio::io_service::work(io_service));
	
		work_ptr.reset(); //will delete the work object
		io_service.run(); //not blocking
	}
	{
		boost::asio::io_service		io_service; 
		boost::asio::deadline_timer	timer(io_service);
		
		timer.expires_from_now(boost::posix_time::milliseconds(1000));
		timer.async_wait(boost::bind(handle_timeout, _1));
		io_service.post(boost::bind(print, "posted"));
		io_service.dispatch(boost::bind(print, "dispatched"));
	
		io_service.run();
	}
	{
		boost::asio::io_service		io_service;
		boost::asio::io_service::work	work(io_service);
		boost::asio::deadline_timer	timer0(io_service);
		boost::asio::deadline_timer	timer1(io_service);
		
		timer0.expires_from_now(boost::posix_time::milliseconds(1000));
		timer0.async_wait(boost::bind(handle_timeout, &timer0, _1));
		timer1.expires_from_now(boost::posix_time::milliseconds(1000));
		timer1.async_wait(boost::bind(handle_timeout, &timer0, _1));
	
//		io_service.run();
		boost::this_thread::sleep(boost::posix_time::milliseconds(5000));
		io_service.poll();
	}
	{
		boost::asio::io_service		io_service; 
		boost::asio::deadline_timer	timer(io_service);
		
		timer.expires_from_now(boost::posix_time::milliseconds(1000));
		timer.async_wait(boost::bind(print, "timedout"));
		io_service.post(boost::bind(print, "posted"));
		io_service.dispatch(boost::bind(print, "dispatched"));
	
		io_service.run();
	}
	{
		boost::asio::io_service		io_service; 
		boost::asio::io_service::work	work(io_service);
		bool error=false;

		io_service.post(handle_00);
		try
		{
			io_service.run();
		}
		catch(int e)
		{
			error=true;
		}
		assert(error);
	}
	return 0;
}
