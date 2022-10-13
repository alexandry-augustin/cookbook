#ifndef BASETCPCLIENT_H
#define BASETCPCLIENT_H

#include <string>
#include <list>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/system/system_error.hpp>
#include <boost/signals.hpp>

class BaseTCPSocket;
namespace base {
class Any;
namespace event {
class Event;
} //namespace event
} //namespace base

typedef boost::signal<void (base::event::Event*)>	event_signal_type;
typedef std::map<std::string, event_signal_type*>	SignalGroup;
class BaseTCPClient
{
	BaseTCPSocket*		_socket;
	SignalGroup		_signalGroup;
	
	void handle_connect(const boost::system::error_code& error);
	
public:
	BaseTCPClient(boost::asio::io_service& io_service);
	~BaseTCPClient();
	
	BaseTCPSocket*	getSocket();
	SignalGroup*	getSignalGroup();
	/*virtual*/ std::string str() const;
	
	bool sync_connect(boost::asio::ip::tcp::endpoint endpoint);
	void async_connect(boost::asio::ip::tcp::endpoint endpoint);
};

#endif
