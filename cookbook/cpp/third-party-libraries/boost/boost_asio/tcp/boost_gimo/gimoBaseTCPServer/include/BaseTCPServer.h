#ifndef BASETCPSERVER_H
#define BASETCPSERVER_H

#include <algorithm>
#include <string>
#include <map>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>
#include <boost/array.hpp>
#include <boost/signals.hpp>
#include <gimo/Util.h>
#include <gimo/BaseConfiguration.h>

class BaseTCPSocket;
namespace base {
class Any;
namespace event {
class Event;
} //namespace event
} //namespace base 

typedef boost::signal<void (base::event::Event*)>	event_signal_type;
typedef std::map<std::string, event_signal_type*>	SignalGroup;
class BaseTCPServer
{
	boost::asio::io_service& 		_io_service;
	boost::asio::ip::tcp::endpoint&		_endpoint;
	boost::asio::ip::tcp::acceptor 		_acceptor;
	SignalGroup				_signalGroup;
	
	void handle_accept(const boost::system::error_code& error,
		boost::asio::ip::tcp::socket* socket);
	
public:
	BaseTCPServer(boost::asio::io_service& io_service,
		boost::asio::ip::tcp::endpoint& endpoint);
	~BaseTCPServer();
	
	SignalGroup* getSignalGroup();
	boost::asio::ip::tcp::endpoint& getEndpoint() const;
	void sync_accept(boost::asio::ip::tcp::socket* socket);
	void sync_accept(BaseTCPSocket* socket);
	void async_accept();
	std::string str() const;
};

#endif
