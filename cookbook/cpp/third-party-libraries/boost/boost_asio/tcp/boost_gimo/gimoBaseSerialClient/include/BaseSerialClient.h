#ifndef BASESERIALCLIENT_H 
#define BASESERIALCLIENT_H 

#include <string>
#include <list>
#include <boost/array.hpp>
#include <boost/signals.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

#define BUFFERSIZE 512

namespace base {
class Any;
namespace event {
class Event;
} //namespace event
} //namespace base

typedef boost::signal<void (base::event::Event*)>	event_signal_type;
typedef std::map<std::string, event_signal_type*>	SignalGroup;
class BaseSerialClient
{
	boost::asio::io_service& 	_io_service;
	boost::asio::serial_port	_serialPort;
	boost::array<char, BUFFERSIZE> 	_readBuffer;
	SignalGroup			_signalGroup;
	char*				_header; //serial message header
	char*				_footer; //serial message footer
	
	void handle_write(const boost::system::error_code& error, std::size_t bytes_transferred, const boost::array<char, BUFFERSIZE>& buffer);
	void handle_read_some(const boost::system::error_code& error, std::size_t bytes_transferred);
	
public:
	BaseSerialClient(boost::asio::io_service& io_service, std::string comName);
	~BaseSerialClient();
	
	SignalGroup*			getSignalGroup();
	boost::asio::serial_port*	getSerialPort();
	
	char getMessageHeader() const;
	void setMessageHeader(char msg);
	char getMessageFooter() const;
	void setMessageFooter(char msg);
	
	/*virtual*/ std::string str() const;
	
	//void read_some()
	void async_read_some();
	
	void sync_write(std::string message);
	void async_write(std::string message);
};

#endif
