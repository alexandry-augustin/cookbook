#include "BaseTCPSocket.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <boost/thread.hpp>
#include <gimo/BaseDateTime.h>
#include <gimo/Util.h>
#include <gimo/BaseEvent.h>
#include <gimo/BaseAny.h>
#include <gimo/BaseAnyFactory.h>
#include <gimo/BaseEventFactory.h>
#include <gimo/BaseException.h>
#include <gimo/BaseSignal.h>

BaseTCPSocket::BaseTCPSocket(boost::asio::io_service& io_service, boost::asio::ip::tcp::socket* socket):
	_io_service(io_service),
//	_current_read_delimiter(BaseTCPSocket::STRING),
//	_string_read_delimiter("\n"),
	_string_write_delimiter(""),
	_pattern_read_delimiter("\n"),
	_eof("#eof#"),
	_socket(socket)
{
	_signalGroup["event.tcp_socket_eof"]=new event_signal_type();
	_signalGroup["event.tcp_socket_sync_write_ack"]=new event_signal_type();
	_signalGroup["event.tcp_socket_sync_write_some_ack"]=new event_signal_type();
	_signalGroup["event.tcp_socket_async_write_some_ack"]=new event_signal_type();
	_signalGroup["event.tcp_socket_async_write_ack"]=new event_signal_type();
	_signalGroup["event.tcp_socket_async_read_until"]=new event_signal_type();
	_signalGroup["event.tcp_socket_async_read_some"]=new event_signal_type();
	
	if(_socket==NULL)
		_socket=new boost::asio::ip::tcp::socket(_io_service);
}

BaseTCPSocket::~BaseTCPSocket()
{
	if(is_open())
		_socket->close();
}

SignalGroup* BaseTCPSocket::getSignalGroup()
{
	return &_signalGroup;
}

boost::asio::ip::tcp::socket* BaseTCPSocket::getSocket()
{
	return _socket;
}

void BaseTCPSocket::setSocket(boost::asio::ip::tcp::socket* socket)
{
	_socket=socket;
}

//BaseTCPSocket::Delimiter BaseTCPSocket::getCurrentDelimiter() const
//{
//	return _current_delimiter;
//}

//void BaseTCPSocket::setCurrentDelimiter(BaseTCPSocket::Delimiter delimiter)
//{
//	_current_delimiter=delimiter;
//}

std::string BaseTCPSocket::getStringWriteDelimiter() const
{
	return _string_write_delimiter;
}

void BaseTCPSocket::setStringWriteDelimiter(std::string str)
{
	_string_write_delimiter=str;
	
	std::cout<<"[BaseTCPSocket::setStringWriteDelimiter] String delimiter for writting set to ["<<base::readable(_string_write_delimiter)<<"]."<<std::endl;
}

base::Regex BaseTCPSocket::getPatternReadDelimiter() const
{
	return _pattern_read_delimiter;
}

void BaseTCPSocket::setPatternReadDelimiter(base::Regex pattern)
{
	_pattern_read_delimiter=pattern;
	
	std::cout<<"[BaseTCPSocket::setPatternDelimiter] Pattern delimiter for reading set to ["<<base::readable(_pattern_read_delimiter.str())<<"]."<<std::endl;
}

bool BaseTCPSocket::connect(boost::asio::ip::tcp::endpoint endpoint)
{
	assert(_socket!=NULL);
	
	if(is_open())
	{
		std::cout<<"[BaseTCPSocket::connect] Already connected."<<std::endl;
		
		return true;
	}
	
	std::cout<<"[BaseTCPSocket::connect] Connecting to server ["<<endpoint.address().to_string()<<":"<<endpoint.port()<<"]..."<<std::endl;
	while(1)
	{
		try
		{
			_socket->connect(endpoint);
			break;
		}
		catch(const boost::system::system_error& e)
		{
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}
	}
	
	async_read_some(); //FIXME
	
	return is_open();
}

void BaseTCPSocket::shutdown(bool shutdown)
{
	//Shutdown the receive side of the socket:
	//	boost::asio::ip::tcp::socket::shutdown_receive
	//Shutdown the send side of the socket:
	//	boost::asio::ip::tcp::socket::shutdown_send
	//Shutdown both send and receive on the socket:	
	//	boost::asio::ip::tcp::socket::shutdown_both
	
	if(shutdown)
		_socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	else
		_socket->shutdown(boost::asio::ip::tcp::socket::shutdown_receive);
}

bool BaseTCPSocket::is_open()
{
	return _socket->is_open();
}

void BaseTCPSocket::close()
{
	if(!is_open())
	{
		std::cerr<<"[BaseTCPSocket::close] Socket is not open."<<std::endl;
		
		return;
	}
	
	try
	{
		_socket->close();
	}
	catch(std::exception e)
	{
		assert(false);
	}	
}

BaseMessage BaseTCPSocket::sync_read_until()
{
	assert(_socket!=NULL);
	
	if(!is_open())
		throw base::Exception("[BaseTCPSocket::sync_read_until] Socket not opened");
	
/*	std::string delimiter;
	switch(_current_read_delimiter)
	{
	case BaseTCPSocket::STRING:
		delimiter=getStringDelimiter();
		break;
	case BaseTCPSocket::PATTERN:
		delimiter=getPatternDelimiter().str();
		break;
	default:
		assert(false);
	}
	std::cout<<"[BaseTCPSocket::read_until] Request for reading until ["<<base::readable(delimiter)<<"]."<<std::endl;*/
	std::cout<<"[BaseTCPSocket::sync_read_until] Request for reading until ["<<base::readable(_pattern_read_delimiter.str())<<"]."<<std::endl;
	boost::asio::streambuf buffer; 
	std::size_t bytes_transferred;
	try
	{
		
		bytes_transferred=boost::asio::read_until(*_socket, buffer, _pattern_read_delimiter.get());
//		assert(bytes_transferred==buffer.size()); //TODO
/*		switch(_current_delimiter)
		{
		case BaseTCPSocket::STRING:
			bytes_transferred=boost::asio::read_until(*_socket, buffer, _string_delimiter);
			break;
		case BaseTCPSocket::PATTERN:
			bytes_transferred=boost::asio::read_until(*_socket, buffer, _pattern_delimiter.get());
			break;
		}*/
		
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			return bMessage;
		}
		
		std::cerr<<"[BaseTCPSocket::sync_read_until] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
	
	//convert the boost::asio::streambuf into std::string
	boost::asio::streambuf::const_buffers_type bufs=buffer.data();
	std::string message(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs)+bytes_transferred);
	assert(buffer.size()==message.size());
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	return bMessage;
}

BaseMessage BaseTCPSocket::sync_read()
{
	assert(_socket!=NULL);
	
	if(!is_open())
		throw base::Exception("[BaseTCPSocket::sync_read] Socket not opened");
	
	boost::asio::streambuf buffer; 
	std::cout<<"[BaseTCPSocket::sync_read] Request for synchronous read."<<std::endl;
	std::size_t bytes_transferred;
	try
	{
		bytes_transferred=boost::asio::read(*_socket, buffer);
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::SYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			return bMessage;
		}
		
		std::cerr<<"[BaseTCPSocket::sync_read] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
	
	//convert the boost::asio::streambuf into std::string
	boost::asio::streambuf::const_buffers_type bufs=buffer.data();
	std::string message(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs)+bytes_transferred);
	assert(buffer.size()==message.size());
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	return bMessage;
}

void BaseTCPSocket::async_read_until()
{
	assert(_socket!=NULL);
	
/*	std::string delimiter;
	switch(_current_delimiter)
	{
	case BaseTCPSocket::STRING:
		delimiter=getStringDelimiter();
		break;
	case BaseTCPSocket::PATTERN:
		delimiter=getPatternDelimiter().str();
		break;
	default:
		assert(false);
	}
	std::cout<<"[BaseTCPSocket::read_until] Request for reading until ["<<base::readable(delimiter)<<"]."<<std::endl;*/
	std::cout<<"[BaseTCPSocket::async_read_until] Request for reading until ["<<base::readable(_pattern_read_delimiter.str())<<"]."<<std::endl;
	try
	{	
		boost::asio::async_read_until(*_socket, _buffer_read_until/*boost::asio::buffer(_buffer_read_some)*/, _pattern_read_delimiter.get(),
			boost::bind(&BaseTCPSocket::handle_read_until, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)); 
//		switch(_current_delimiter)
//		{
//		case BaseTCPSocket::STRING:
//			boost::asio::async_read_until(*_socket, _buffer_read_until/*boost::asio::buffer(_buffer_read_some)*/, _string_delimiter,
//				boost::bind(&BaseTCPSocket::handle_read_until, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)); 
//			break;
//		case BaseTCPSocket::PATTERN:
//			boost::asio::async_read_until(*_socket, _buffer_read_until/*boost::asio::buffer(_buffer_read_some)*/, _pattern_delimiter.get(),
//				boost::bind(&BaseTCPSocket::handle_read_until, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)); 
//			break;
//		}
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		} 
		
		std::cerr<<"[BaseTCPSocket::async_read_until] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
}

void BaseTCPSocket::handle_read_until(const boost::system::error_code& error, std::size_t bytes_transferred)
{
	if(error) //cf boost/asio/error.hpp
	{
		if(error==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		} 
		
/*		if(error==boost::asio::error::not_connected) // Transport endpoint is not connected
			return;		*/
		
		std::cout<<"[BaseTCPSocket::handle_read_until] Error: "<<error.message()<<"."<<std::endl;
		return;
	}
	
	//convert the boost::asio::streambuf into std::string
	boost::asio::streambuf::const_buffers_type bufs=_buffer_read_until.data();
	std::string message(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs)+bytes_transferred);
	//assert(_buffer_read_until.size()==message.size());
	_buffer_read_until.consume(bytes_transferred); //clear buffer. Rem: read_until() may read more data than asked, so we don't want to clear the whole buffer.
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_async_read_until");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_async_read_until")->second, event);
	
	boost::asio::async_read_until(*_socket, _buffer_read_until/*boost::asio::buffer(_buffer_read_some)*/, _pattern_read_delimiter.get(),
		boost::bind(&BaseTCPSocket::handle_read_until, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

BaseMessage BaseTCPSocket::sync_read_some()
{
	assert(_socket!=NULL);
	
	std::cout<<"[BaseTCPSocket::sync_read_some] Request for synchronous read."<<std::endl;
	_buffer_read_some.fill('\0');
	std::size_t bytes_transferred;
	try
	{
		bytes_transferred=_socket->read_some(boost::asio::buffer(_buffer_read_some));
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::SYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			return bMessage;
		}
		
		std::cerr<<"[BaseTCPSocket::sync_read_some] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
	
	//convert the buffer into a std::string
	std::string message;
	std::copy(_buffer_read_some.begin(), _buffer_read_some.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	return bMessage;
}

void BaseTCPSocket::async_read_some()
{
	assert(_socket!=NULL);
	
	std::cout<<"[BaseTCPSocket::async_read_some] Request asynchronous read."<<std::endl;
	_buffer_read_some.fill('\0');
	try
	{
		_socket->async_read_some(boost::asio::buffer(_buffer_read_some),
			boost::bind(&BaseTCPSocket::handle_read_some, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
	catch(const boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cerr<<"[BaseTCPSocket::async_read_some] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
}

void BaseTCPSocket::handle_read_some(const boost::system::error_code& error, std::size_t bytes_transferred)
{
	if(error)
	{
		if(error==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::RECEIVED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cout<<"[BaseTCPSocket::handle_read_some] Error: "<<error.message()<<"."<<std::endl;
		return;
	}
	
	//convert the buffer into a std::string
	std::string message;
	//boost::array<char, BUFFERSIZE> buffer;
	std::copy(_buffer_read_some.begin(), _buffer_read_some.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_async_read_some");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_async_read_some")->second, event);
	
	_buffer_read_some.fill('\0');
	_socket->async_read_some(boost::asio::buffer(_buffer_read_some),
		boost::bind(&BaseTCPSocket::handle_read_some, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void BaseTCPSocket::sync_write_some(std::string message)
{
	assert(!message.empty());
	
	boost::array<char, BUFFERSIZE> buffer;
	buffer.fill('\0');
	message.append(_string_write_delimiter);
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		_socket->write_some(boost::asio::buffer(buffer, message.length()));
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::SYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cerr<<"[BaseTCPSocket::sync_write_some] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_sync_write_some_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_sync_write_some_ack")->second, event);
	
}

void BaseTCPSocket::async_write_some(std::string message)
{
	assert(_socket!=NULL);
	assert(!message.empty());
	
	message.append(_string_write_delimiter);
	boost::array<char, BUFFERSIZE> buffer;
	buffer.fill('\0');
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		_socket->async_write_some(boost::asio::buffer(message),
			boost::bind(&BaseTCPSocket::handle_write_some, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, buffer));
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cerr<<"[BaseTCPSocket::async_write_some] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
}

void BaseTCPSocket::handle_write_some(const boost::system::error_code& error,
	std::size_t bytes_transferred,
	const boost::array<char, BUFFERSIZE>& buffer)
{
	if(error)
	{
		if(error==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cout<<"[BaseTCPSocket::handle_write_some] Error: "<<error.message()<<"."<<std::endl;
		return;
	}
	
	std::string message;
	std::copy(buffer.begin(), buffer.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_async_write_some_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_async_write_some_ack")->second, event);
}

void BaseTCPSocket::sync_write(std::string message)
{
	assert(_socket!=NULL);
	assert(!message.empty());
	
	message.append(_string_write_delimiter);
	boost::array<char, BUFFERSIZE> buffer;
	buffer.fill('\0');
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		boost::asio::write(*_socket, boost::asio::buffer(buffer));
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::SYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cerr<<"[BaseTCPSocket::async_write] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_sync_write_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_sync_write_ack")->second, event);
}

void BaseTCPSocket::async_write(std::string message) const
{
	assert(_socket!=NULL);
	assert(!message.empty());
	
	message.append(_string_write_delimiter);
	boost::array<char, BUFFERSIZE> buffer;
	buffer.fill('\0');
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		boost::asio::async_write(*_socket, boost::asio::buffer(message), 
			boost::bind(&BaseTCPSocket::handle_write, const_cast<BaseTCPSocket*>(this), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, buffer));
	}
	catch(boost::system::system_error& e)
	{
		if(e.code()==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cerr<<"[BaseTCPSocket::async_write] Exception: "<<e.what()<<"."<<std::endl;
		throw e;
	}
}

void BaseTCPSocket::handle_write(const boost::system::error_code& error,
	std::size_t bytes_transferred,
	const boost::array<char, BUFFERSIZE>& buffer)
{
	if(error)
	{
		if(error==boost::asio::error::eof) //socket closed
		{
			BaseMessage bMessage;
			bMessage.setDateTime(BaseDateTime::now());
			bMessage.setMessage(_eof);
			bMessage.setDirection(BaseMessage::TRANSMITTED);
			bMessage.setSync(BaseMessage::ASYNC);
			bMessage.setSource(BaseMessage::TCP);
			
			base::event::Event* event=base::event::Factory::get("event.tcp_socket_eof");
			event->setDebugInfo(_DEBUG_INFO_());
			event->getArgs()->push_back(base::any::Factory::get(bMessage));
			base::event::notify(_signalGroup.find("event.tcp_socket_eof")->second, event);
			
			return;
		}
		
		std::cout<<"[BaseTCPSocket::handle_write] Error: "<<error.message()<<"."<<std::endl;
		
		return;
	}
	
	std::string message;
	std::copy(buffer.begin(), buffer.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::TCP);
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_async_write_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.tcp_socket_async_write_ack")->second, event);
}

///*static*/ std::string BaseTCPSocket::str(BaseTCPSocket::Delimiter delimiter) 
//{
//	switch(delimiter)
//	{
//	case BaseTCPSocket::STRING:
//		return "string";
//	case BaseTCPSocket::PATTERN:
//		return "regex";
//	}
//}

std::string BaseTCPSocket::str() /*const*/
{
	if(getSocket()==NULL)
		return "[N/A]";
	
	std::stringstream ss;
	ss<<"["<<getSocket()->remote_endpoint().address().to_string()<<":"<<
		getSocket()->remote_endpoint().port()<<"]";
	
	return ss.str();
}