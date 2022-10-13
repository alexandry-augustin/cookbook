#ifndef BASETCPSOCKET_H
#define BASETCPSOCKET_H

#include <string>
#include <map>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/signals.hpp>
#include <boost/system/system_error.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <gimo/BaseMessage.h>
#include <gimo/BaseRegex.h>

namespace base {
class Any;
namespace event {
class Event;
} //namespace event
} //namespace base 

//http://www.cplusplus.com/reference/clibrary/climits/
#define BUFFERSIZE 1000000

typedef boost::signal<void (base::event::Event*)>	event_signal_type;
typedef std::map<std::string, event_signal_type*>	SignalGroup;
class BaseTCPSocket
{
public:
/*	enum Delimiter
	{
		CHAR,
		STRING,
		PATTERN
	};*/
private:
	
	boost::asio::io_service&	_io_service;
	boost::asio::ip::tcp::socket*	_socket;
	boost::array<char, BUFFERSIZE> 	_buffer_read_some;	//for boost::asio::read_some
	boost::asio::streambuf 		_buffer_read_until;	//for boost::asio::read_until
	std::string			_eof;
	SignalGroup			_signalGroup;
	
//	BaseTCPSocket::Delimiter	_current_read_delimiter;
//	std::string 			_string_read_delimiter;
	base::Regex			_pattern_read_delimiter;
	std::string 			_string_write_delimiter;
	
	void handle_write(const boost::system::error_code& error, std::size_t bytes_transferred, const boost::array<char, BUFFERSIZE>& buffer);
	void handle_write_some(const boost::system::error_code& error, std::size_t bytes_transferred, const boost::array<char, BUFFERSIZE>& buffer);
	void handle_read_some(const boost::system::error_code& error, std::size_t bytes_transferred);
	void handle_read_until(const boost::system::error_code& error, std::size_t bytes_transferred);
	
public:
	BaseTCPSocket(boost::asio::io_service& io_service, boost::asio::ip::tcp::socket* socket=NULL);
	~BaseTCPSocket();
	
	SignalGroup* getSignalGroup();
	void shutdown(bool shutdown);	//disable sends or receives
	bool connect(boost::asio::ip::tcp::endpoint endpoint);
	bool is_open();
	void close();
	boost::asio::ip::tcp::socket* getSocket();
	void setSocket(boost::asio::ip::tcp::socket* socket);
	/*virtual*/ std::string str() /*const*/;
//	/*static*/ std::string str(BaseTCPSocket::Delimiter delimiter);
	
//	BaseTCPSocket::Delimiter getCurrentReadDelimiter() const;
//	void setCurrentReadDelimiter(BaseTCPSocket::Delimiter delimiter);
//	std::string getStringReadDelimiter() const;
//	void setStringReadDelimiter(std::string str);	
	std::string getStringWriteDelimiter() const;
	void setStringWriteDelimiter(std::string str);
	base::Regex getPatternReadDelimiter() const;
	void setPatternReadDelimiter(base::Regex pattern);
	
	BaseMessage sync_read();
	BaseMessage sync_read_until();
	void async_read_until();
	BaseMessage sync_read_some();
	void async_read_some();
	
	void sync_write(std::string message);
	void async_write(std::string message) const;
	void sync_write_some(std::string message);
	void async_write_some(std::string message);
};

#endif
