#ifndef BASE_IO_SERVICE_H
#define BASE_IO_SERVICE_H

#include <boost/asio.hpp> 
#include <cstddef>
#include "base_io_service_implementation.h"

template <typename TimerImplementation=base_io_service_implementation>
class base_io_service:
	public boost::asio::io_service::service 
{ 
	boost::asio::io_service					async_io_service_; 
	boost::scoped_ptr<boost::asio::io_service::work>	async_work_; 
	boost::thread						async_thread_; 

	void shutdown_service() 
	{ 
	} 
public:
	static boost::asio::io_service::id id; 

	explicit base_io_service(boost::asio::io_service &io_service):
		boost::asio::io_service::service(io_service),
		async_work_(new boost::asio::io_service::work(async_io_service_)), 
		async_thread_(boost::bind(&boost::asio::io_service::run, &async_io_service_)) 
	{ 
	}
	~base_io_service() 
	{ 
		async_work_.reset(); 
		async_io_service_.stop(); 
		async_thread_.join(); 
	}
	typedef boost::shared_ptr<TimerImplementation> implementation_type; 
	void construct(implementation_type& impl) 
	{ 
		impl.reset(new TimerImplementation()); 
	} 
	void destroy(implementation_type &impl) 
	{ 
		impl->destroy(); 
		impl.reset(); 
	} 
	void wait(implementation_type& impl, std::string str) 
	{ 
		boost::system::error_code e; 
		impl->sync_print(str, e); 
		boost::asio::detail::throw_error(e); 
	} 
	template <typename Handler> 
	class wait_operation 
	{ 
		boost::weak_ptr<TimerImplementation>	impl_; 
		boost::asio::io_service&		io_service_; 
		boost::asio::io_service::work		work_; 
		std::string				_str; 
		Handler					handler_; 
	public: 
		wait_operation(implementation_type &impl,
			boost::asio::io_service &io_service,
			std::string str, Handler handler):
			impl_(impl), 
			io_service_(io_service), 
			work_(io_service), 
			_str(str), 
			handler_(handler) 
		{ 
		} 
		void operator()() const 
		{ 
			implementation_type impl=impl_.lock(); 
			if (impl) 
			{ 
				boost::system::error_code e; 
				impl->sync_print(_str, e); 
				io_service_.post(boost::asio::detail::bind_handler(handler_, e)); 
			} 
			else 
			{ 
				io_service_.post(boost::asio::detail::bind_handler(handler_, boost::asio::error::operation_aborted)); 
			} 
		} 
	}; 
	template <typename Handler> 
	void async_print(implementation_type& impl, std::string str, Handler handler) 
	{ 
		async_io_service_.post(wait_operation<Handler>(impl, get_io_service(), str, handler)); 
	}
};

template <typename TimerImplementation> 
boost::asio::io_service::id base_io_service<TimerImplementation>::id;

#endif
