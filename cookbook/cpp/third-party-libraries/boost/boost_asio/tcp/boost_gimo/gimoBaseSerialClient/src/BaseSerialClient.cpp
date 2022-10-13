#include "BaseSerialClient.h"
#include <iostream>
#include <sstream>
#include <boost/thread.hpp>
#include <gimo/Util.h>
#include <gimo/BaseTime.h>
#include <gimo/BaseAny.h>
#include <gimo/BaseAnyFactory.h>
#include <gimo/BaseException.h>
#include <gimo/BaseMessage.h>
#include <gimo/BaseEvent.h>
#include <gimo/BaseEventFactory.h>
#include <gimo/BaseSignal.h>

BaseSerialClient::BaseSerialClient(boost::asio::io_service& io_service,
	std::string comName)
	try :
		_header(NULL),
		_footer(NULL),
		_io_service(io_service),
		_serialPort(io_service, comName)
{	
	//connected (cf constructor of boost::asio::serial_port )
	try
	{
		_serialPort.set_option(boost::asio::serial_port_base::baud_rate(9600));
		_serialPort.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
		_serialPort.set_option(boost::asio::serial_port_base::character_size(8));
		_serialPort.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));	// default one
		_serialPort.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
	}
	catch(std::exception& e)
	{
		assert(false);
		//std::cerr<<"[BaseSerialClient::BaseSerialClient] Exception: "<<e.what()<<"."<<std::endl; //Serial COM not found.
		throw base::Exception("[BaseSerialClient::BaseSerialClient] Exception: "+std::string(e.what()));
	}
	
	_readBuffer.fill('\0');
	async_read_some();
	
	//_signalGroup[base::event::Type::TYPE_SERIAL_SOCKET_EOF_]=new event_signal_type(); //TODO
	_signalGroup["event.serialport_sync_write_ack"]=new event_signal_type();
	_signalGroup["event.serialport_async_write_ack"]=new event_signal_type();
	_signalGroup["event.serialport_async_read_some"]=new event_signal_type();
}
catch(const std::exception& e)
{
	assert(false);
	
	//std::cerr<<"[BaseSerialClient::BaseSerialClient] Exception: "<<e.what()<<"."<<std::endl; //Serial COM not found.
	throw base::Exception("[BaseSerialClient::BaseSerialClient::init_list] Exception: "+std::string(e.what())+".\n"
		+"[BaseSerialClient::BaseSerialClient::init_list] Device ["+comName+"] could not be found");
}

BaseSerialClient::~BaseSerialClient()
{
	if(_serialPort.is_open())
		_serialPort.close();
}

boost::asio::serial_port* BaseSerialClient::getSerialPort()
{
	return &_serialPort;
}

char BaseSerialClient::getMessageHeader() const
{
	assert(_header!=NULL);
	
	return *_header;
}

void BaseSerialClient::setMessageHeader(char msg)
{
	_header=new char(msg);
}

char BaseSerialClient::getMessageFooter() const
{
	assert(_footer!=NULL);
	
	return *_footer;
}

void BaseSerialClient::setMessageFooter(char msg)
{
	_footer=new char(msg);
}

SignalGroup* BaseSerialClient::getSignalGroup()
{
	return &_signalGroup;
}

/*bool BaseSerialClient::isConnected()
{
	return _serialPort.is_open();
}

void BaseSerialClient::close()
{
	if(isConnected())
		_serialPort.close(); //socket is closed so that any outstanding asynchronous operations are cancelled.
}*/

/*void BaseSerialClient::open()
{
	if(!isConnected())
		_serialPort.open();
}*/

/*void BaseSerialClient::cancel()
{
	if(isConnected())
		_serialPort.cancel();  //cancel all asynchronous operations associated with the serial port.
}*/

/*void BaseSerialClient::read_some()
{
	try
	{
		//_serialPort.read_some(boost::asio::buffer(_readBuffer));
	}
	catch(std::exception& e)
	{
		//std::cerr<<"[BaseSerialClient::read_some] Exception: "<<e.what()<<"."<<std::endl;
		throw base::Exception("[BaseSerialClient::read_some] Exception: ");
	}
}*/

void BaseSerialClient::async_read_some()
{
	try
	{
		_serialPort.async_read_some(boost::asio::buffer(_readBuffer),
			boost::bind(&BaseSerialClient::handle_read_some, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
	catch(const std::exception& e)
	{
		//std::cerr<<"[BaseSerialClient::async_read_some] Exception: "<<e.what()<<"."<<std::endl;
		assert(false);
		throw base::Exception("[BaseSerialClient::async_read_some] Exception: "+std::string(e.what()));
	}
}

void BaseSerialClient::handle_read_some(const boost::system::error_code& error, std::size_t bytes_transferred)
{
	if(error)
	{
		if(error==boost::asio::error::operation_aborted) //when _serialPort.cancel() invoked
			async_read_some();
		else
			std::cout<<"[BaseSerialClient::handle_read_some] Error: "<<error.message()<<"."<<std::endl;
		
		return;
	}
//std::cout<<"###"<<_readBuffer.c_array()<<std::endl;
//std::cout<<"### "<<bytes_transferred<<std::endl;

//avoid double reading of the same card
boost::this_thread::sleep(boost::posix_time::milliseconds(200));
	
	//convert the buffer into a std::string
	std::string message;
	//boost::array<char, BUFFERSIZE> buffer;
	std::copy(_readBuffer.begin(), _readBuffer.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::SERIAL);
	
	base::event::Event* event=base::event::Factory::get("event.serialport_async_read_some");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.serialport_async_read_some")->second, event);
	
	_readBuffer.fill('\0');
	async_read_some();
}

void BaseSerialClient::sync_write(std::string message)
{
	if(!_serialPort.is_open())
	{
		assert(false);
		//std::cerr<<"[BaseSerialClient::write] Error: No connection to serial port."<<std::endl;
		throw base::Exception("[BaseSerialClient::write] No connection to serial port");
	}

	boost::array<char, BUFFERSIZE> buffer;
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		boost::asio::write(_serialPort, boost::asio::buffer(message));
	}
	catch(boost::system::system_error& e)
	{
		assert(false);
//		std::cerr<<"[BaseSerialClient::write] Exception: "<<e.what()<<"."<<std::endl;
		throw base::Exception("[BaseSerialClient::write] Exception: "+std::string(e.what()));
	}
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::SERIAL);
	
	base::event::Event* event=base::event::Factory::get("event.serialport_sync_write_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.serialport_sync_write_ack")->second, event);
}

void BaseSerialClient::async_write(std::string message)
{
	if(!_serialPort.is_open())
	{
		std::cerr<<"[BaseSerialClient::async_write] Error: No connection to serial port."<<std::endl;
		assert(false);
		throw std::exception();
	}
	
	boost::array<char, BUFFERSIZE> buffer;
	std::copy(message.begin(), message.end(), buffer.begin());
	try
	{
		//_serialPort.async_write_some(boost::asio::buffer(message), boost::bind(&BaseSerialClient::handle_write_some, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, buffer));
		boost::asio::async_write(_serialPort, boost::asio::buffer(message), boost::bind(&BaseSerialClient::handle_write, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, buffer));
	}
	catch(std::exception& e)
	{
		assert(false);
		//std::cerr<<"[BaseSerialClient::async_write] Exception: "<<e.what()<<"."<<std::endl;
		throw base::Exception("[BaseSerialClient::async_write] Exception: "+std::string(e.what()));
	}
}

void BaseSerialClient::handle_write(const boost::system::error_code& error, std::size_t bytes_transferred, const boost::array<char, BUFFERSIZE>& buffer)
{
	if(error)
	{
		std::cerr<<"[BaseSerialClient::async_write] Error: "<<error.message()<<"."<<std::endl;
		assert(false);
		return;
	}
	
	std::string message;
	std::copy(buffer.begin(), buffer.begin()+bytes_transferred, std::back_inserter(message));
	
	BaseMessage bMessage;
	bMessage.setDateTime(BaseDateTime::now());
	bMessage.setMessage(message);
	bMessage.setDirection(BaseMessage::TRANSMITTED);
	bMessage.setSync(BaseMessage::ASYNC);
	bMessage.setSource(BaseMessage::SERIAL);
	
	base::event::Event* event=base::event::Factory::get("event.serialport_async_write_ack");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bMessage));
	base::event::notify(_signalGroup.find("event.serialport_async_write_ack")->second, event);
}

/*virtual*/ std::string BaseSerialClient::str() const
{
	std::stringstream ss;
	ss<<"BaseSerialClient";
	
	return ss.str();
}
