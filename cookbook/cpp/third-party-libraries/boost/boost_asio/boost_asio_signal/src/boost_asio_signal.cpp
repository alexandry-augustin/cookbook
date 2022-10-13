#include <iostream>
#include <sstream>
#include <cassert>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

void handler(boost::asio::io_service* io_service,
	boost::asio::signal_set* signal_set,
	const boost::system::error_code& ec,
	int signal_number)
{
	if(ec.value()!=boost::system::errc::success)
	{
		std::cerr<<"error: "<<ec.message()<<std::endl;
		return;
	}
	std::cout<<"signal ["<<signal_number<<"] received. quit? [y/n]: ";
	char c;
	std::cin>>c;
	if(c=='y')
		io_service->stop();
	else
	{
		signal_set->async_wait(boost::bind(handler, io_service, signal_set, _1, _2));
		std::cout<<"waiting for signal..."<<std::endl;
	}
}

// pkill -0 -f ./boost_asio_signal
//
// pgrep -f ./boost_asio_signal //get pid
// kill -9 pid

int main()
{
	{
		boost::asio::io_service		io_service;
		boost::asio::io_service::work	work(io_service);
		boost::asio::signal_set		signal_set(io_service, SIGINT, SIGTERM);

		signal_set.async_wait(boost::bind(handler, &io_service, &signal_set, _1, _2));
	
		std::cout<<"waiting for signal..."<<std::endl;
		io_service.run();
	}
	return 0;
}
