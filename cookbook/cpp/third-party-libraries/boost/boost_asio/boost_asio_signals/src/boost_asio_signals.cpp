#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals.hpp>
#include <boost/ref.hpp>
#include <boost/any.hpp>

struct Event
{
	std::string			id;
	std::string			data;
	boost::any			arg;
	boost::system::error_code	ec;
};

typedef typename boost::signal<void (Event*)>			signal_type;
typedef typename boost::function<void (Event*)>			handler_type;
typedef typename std::map<std::string, signal_type*>		signal_group_type;

void handler01(Event* event)
{
	std::cout<<"[handler01] "<<(event->data)<<std::endl;
}

void handler02(Event* event)
{
	std::cout<<"[handler02] "<<(event->data)<<std::endl;
}

struct base
{
	boost::asio::io_service		io_service;
	signal_group_type		signal;
	
	void connect(std::string event_id, handler_type handler)
	{
		signal_group_type::iterator it=signal.find(event_id);
		if(it==signal.end())
			//TODO do this fix in stl_map
			it=signal.insert(signal.end(), std::make_pair(event_id, new signal_type()));
		it->second->connect(handler);
	}
	void post(Event* event)
	{
		signal_group_type::iterator it=signal.find(event->id);
		assert(it!=signal.end());
		io_service.post(boost::bind(boost::ref(*(it->second)), event));
//boost::function<void (Event*)> f=;
//boost::bind(f, boost::bind(&signal_group_type::value_type::second, _1));
//io_service.post(boost::bind(it->second, event));
	}
	void post(Event* event, const boost::system::error_code& ec)
	{
		event->ec=ec;
		post(event);
	}
	void handle_print(Event* event)
	{
		std::cout<<(event->data)<<std::flush;
		if(event->data=="hello")
		{
			Event* new_event=new Event();
			new_event->id="event.print";
			new_event->data=" world!\n";
			post(new_event);
		}
	}
	void handle_timeout_(Event* event)
	{
		if(event->ec==boost::asio::error::operation_aborted)
		{
			std::cout<<"cancelled"<<std::endl;
			return;
		}
		std::cout<<"timeout"<<std::endl;
	}
	void handle_timeout(const boost::system::error_code& ec)
	{
		if(ec==boost::asio::error::operation_aborted)
		{
			std::cout<<"cancelled"<<std::endl;
			return;
		}
		std::cout<<"timeout"<<std::endl;
	}
};

void error(const boost::system::error_code& ec)
{
	assert(ec==boost::asio::error::operation_aborted);
}

void set_error(boost::system::error_code& ec)
{
	ec=boost::asio::error::operation_aborted;
}

int main()
{
	{
		boost::asio::io_service		io_service;
		signal_type			signal;
		Event				event;
		
		event.data="hello world!";
		signal.connect(handler01);
		signal.connect(handler02);
	
		io_service.post(boost::bind(boost::ref(signal), &event));
		io_service.poll();
	}
	{
		boost::asio::io_service		io_service;
		signal_group_type		signal;
		Event				event;
		
		event.id="event.print";
		event.data="hello world!";
		signal.insert(std::make_pair(event.id, new signal_type()));
		signal.find(event.id)->second->connect(handler01);
		signal.find(event.id)->second->connect(handler02);
	
		io_service.post(boost::bind(boost::ref(*(signal.find(event.id)->second)), &event));
		io_service.poll();
	}
	{
		base b;
		Event* event=new Event();

		event->id="event.print";
		event->data="hello";
		b.connect(event->id, boost::bind(&base::handle_print, boost::ref(b), _1));
	
		b.post(event);
		b.io_service.poll();
	}
	{
		base b;
		boost::asio::deadline_timer timer(b.io_service);
		Event* event=new Event();
		
		event->id="timeout";
		b.connect(event->id, boost::bind(&base::handle_timeout_, boost::ref(b), _1));
		timer.expires_from_now(boost::posix_time::seconds(3));
	
		//NOTE: boost::asio::placeholders::error alias for _1
		//NOTE: boost::asio::placeholders::bytes_transferred alias for _2
		//timer.async_wait(boost::bind(&base::handle_timeout, boost::ref(b), boost::asio::placeholders::error)); wrong handler signature
		//timer.async_wait(boost::bind(&base::post, boost::ref(b), event)); //no error handling
		timer.async_wait(boost::bind(&base::post, boost::ref(b), event, boost::asio::placeholders::error));

		timer.cancel();
		b.io_service.run();
	}
	{
		boost::function<void (void)> handler;
		Event event;
		
		//event.ec=boost::asio::error::operation_aborted;
		//or
		boost::bind<boost::system::error_code&>(&Event::ec, _1)(event)=boost::asio::error::operation_aborted;
		//assert(event.ec==boost::asio::error::operation_aborted);
	
		//handler=boost::bind(error, event.ec);
		//or
		handler=boost::bind(error, boost::bind<boost::system::error_code&>(&Event::ec, _1)(event));

		handler();
	}
	{
		boost::function<void (void)> handler;
		Event event;
		//Event* event_ptr=new Event();
		
		handler=boost::bind(set_error, boost::bind<boost::system::error_code&>(&Event::ec, _1)(event));
		assert(event.ec!=boost::asio::error::operation_aborted);
	
		handler();
	}
	return 0;
}
