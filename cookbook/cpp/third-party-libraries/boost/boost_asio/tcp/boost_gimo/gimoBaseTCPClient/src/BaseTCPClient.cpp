#include "BaseTCPClient.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <boost/thread.hpp>
#include <gimo/Util.h>
#include <gimo/BaseMessage.h>
#include <gimo/BaseTCPSocket.h>
#include <gimo/BaseException.h>
#include <gimo/BaseEvent.h>
#include <gimo/BaseEventFactory.h>
#include <gimo/BaseSignal.h>

BaseTCPClient::BaseTCPClient(boost::asio::io_service& io_service):
	_socket(new BaseTCPSocket(io_service))
{
	_signalGroup["event.tcp_socket_connected"]=new event_signal_type();
}

BaseTCPClient::~BaseTCPClient()
{
	if(_socket!=NULL)
	{
		if(_socket->is_open())
			_socket->close();
		delete _socket;
	}
}

BaseTCPSocket* BaseTCPClient::getSocket()
{
	return _socket;
}

SignalGroup* BaseTCPClient::getSignalGroup()
{
	return &_signalGroup;
}

bool BaseTCPClient::sync_connect(boost::asio::ip::tcp::endpoint endpoint)
{
	return _socket->connect(endpoint);
}

void BaseTCPClient::async_connect(boost::asio::ip::tcp::endpoint endpoint)
{
	_socket->getSocket()->async_connect(
		endpoint,
		boost::bind(&BaseTCPClient::handle_connect, this,
		boost::asio::placeholders::error));
}

std::string BaseTCPClient::str() const
{
	std::stringstream ss;
	ss<<"BaseTCPClient";
	
	return ss.str();
}

void BaseTCPClient::handle_connect(const boost::system::error_code& e)
{
	if(e) //cf boost/asio/error.hpp
	{
		if(boost::asio::error::connection_refused)
		{
			//server migh be down
			std::cerr<<"[BaseTCPClient::handle_connect] error: "<<e.message()<<std::endl;
			return;
		}
	}
	
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_connected");
	event->setDebugInfo(_DEBUG_INFO_());
	base::event::notify(_signalGroup.find("event.tcp_socket_connected")->second, event);
}