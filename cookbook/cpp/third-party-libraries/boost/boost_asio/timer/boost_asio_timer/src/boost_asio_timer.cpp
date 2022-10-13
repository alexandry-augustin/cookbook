#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/date_time.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
boost::posix_time::time_duration	_time_duration;
boost::posix_time::ptime		_starting_time;
//---------------------------------------------------------
void pass(boost::asio::deadline_timer* timer, const boost::system::error_code& ec)
{
	std::cout<<"timedout"<<std::flush;
}
//---------------------------------------------------------
void handle_timer(const boost::system::error_code& ec)
{
	if(ec!=boost::system::errc::success)
	{
		if(ec==boost::asio::error::operation_aborted)
		{
//			boost::posix_time::time_period running_period=
//				boost::posix_time::microsec_clock::local_time()-_starting_time;
//			deadline_timer.expires_from_now(_time_duration);
//			deadline_timer.async_wait(boost::bind(handle_timer, boost::asio::placeholders::error));
		}
	}
}
//---------------------------------------------------------
void handle_timer(boost::asio::deadline_timer& timer, const boost::system::error_code& ec)
{
	std::cout<<"*"<<std::flush;

	timer.expires_from_now(boost::posix_time::seconds(1)); ///!\ important /!\ got to be reset
	timer.async_wait(boost::bind(handle_timer, boost::ref(timer), boost::asio::placeholders::error));
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	//deadline_timer is not copyable;
	{
		boost::asio::io_service			io_service;
		boost::asio::deadline_timer		deadline_timer(io_service);
		boost::posix_time::ptime		starting_time=boost::posix_time::microsec_clock::local_time();
		boost::posix_time::time_duration	time_duration=boost::posix_time::seconds(5);
		boost::posix_time::time_period		time_period(starting_time, time_duration);
		std::string str;
		
		deadline_timer.expires_from_now(time_duration);
		deadline_timer.async_wait(boost::bind(handle_timer, boost::asio::placeholders::error));
	
		io_service.run_one();

		str=boost::posix_time::to_simple_string(boost::posix_time::microsec_clock::local_time()-starting_time);
		std::cout<<str<<std::endl;
	}
	{
		boost::asio::io_service			io_service;
		boost::asio::deadline_timer		deadline_timer(io_service);
		
		_starting_time=boost::posix_time::microsec_clock::local_time();
		_time_duration=boost::posix_time::seconds(5);
		deadline_timer.expires_from_now(_time_duration);
		deadline_timer.async_wait(boost::bind(handle_timer, boost::asio::placeholders::error));

		io_service.run_one();
	
		boost::posix_time::to_simple_string(boost::posix_time::microsec_clock::local_time()-_starting_time);
	}
	{
		boost::asio::io_service			io_service;
		boost::asio::deadline_timer		deadline_timer(io_service);

		deadline_timer.expires_from_now(boost::posix_time::seconds(1));
		deadline_timer.async_wait(boost::bind(handle_timer, boost::ref(deadline_timer), boost::asio::placeholders::error));

		io_service.run();
	}
	{
		boost::asio::io_service			io_service;
		boost::asio::deadline_timer		deadline_timer(io_service);
		
		deadline_timer.expires_at(
				boost::posix_time::microsec_clock::universal_time()
				+boost::posix_time::seconds(1));
	}
	{
		boost::asio::io_service			io_service;
		boost::asio::deadline_timer		deadline_timer(io_service);

		//expires_from_now(duration)==expires_at(boost::posix_time::microsec_clock::universal_time()+duration)
		deadline_timer.expires_from_now(boost::posix_time::seconds(1));
		std::cout<<"sleeping..."<<std::endl;
		boost::this_thread::sleep(boost::posix_time::seconds(2));
		std::cout<<"woke up!"<<std::endl;
		std::cout<<"running timer"<<std::endl; 
		//will expire immediatly
		deadline_timer.async_wait(boost::bind(pass, &deadline_timer, boost::asio::placeholders::error));

		io_service.run();
	}
	return 0;
}
