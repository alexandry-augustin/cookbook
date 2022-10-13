#include "BaseTCPServer.h"
#include <iostream>
#include <gimo/BaseMessage.h>
#include <gimo/BaseTCPSocket.h>
#include <gimo/BaseEvent.h>
#include <gimo/BaseAny.h>
#include <gimo/BaseAnyFactory.h>
#include <gimo/BaseEventFactory.h>
#include <gimo/BaseSignal.h>

BaseTCPServer::BaseTCPServer(boost::asio::io_service& io_service,
	boost::asio::ip::tcp::endpoint& endpoint):
 	_io_service(io_service),
	_acceptor(io_service, endpoint),
	_endpoint(endpoint)
{
	_signalGroup["event.tcp_socket_accepted"]=new event_signal_type();
}

BaseTCPServer::~BaseTCPServer()
{
}

SignalGroup* BaseTCPServer::getSignalGroup()
{
	return &_signalGroup;
}

boost::asio::ip::tcp::endpoint& BaseTCPServer::getEndpoint() const
{
	return _endpoint;
}

void BaseTCPServer::sync_accept(boost::asio::ip::tcp::socket* socket)
{
	assert(socket!=NULL);
	
	_acceptor.accept(*socket);
}

void BaseTCPServer::sync_accept(BaseTCPSocket* bSocket)
{
	assert(bSocket!=NULL);
	assert(bSocket->getSocket()!=NULL);
	
	sync_accept(bSocket->getSocket());
}

void BaseTCPServer::async_accept()
{
//	boost::asio::ip::tcp::socket* socket=new boost::asio::ip::tcp::socket(_io_service, _endpoint); //open socket and bind it to the given local endpoint
	boost::asio::ip::tcp::socket* socket=new boost::asio::ip::tcp::socket(_io_service);
	
	try
	{
		_acceptor.async_accept(*socket, 
			boost::bind(&BaseTCPServer::handle_accept, this, 
			boost::asio::placeholders::error, socket));
	}
	catch(const std::exception& e)
	{
		std::cerr<<"[BaseTCPServer::accept] Exception: "<<e.what()<<"."<<std::endl;
	}
}

void BaseTCPServer::handle_accept(const boost::system::error_code& error, boost::asio::ip::tcp::socket* socket)
{
	if(error)
	{
		std::cerr<<"[BaseTCPServer::handle_accept] Error: "<<error.message()<<"."<<std::endl;
		
		return;
	}
	
	assert(socket!=NULL);
	std::cout<<"[BaseTCPServer::handle_accept] Connection established."<<std::endl;
	
	BaseTCPSocket* bSocket=new BaseTCPSocket(_io_service, socket);
	base::event::Event* event=base::event::Factory::get("event.tcp_socket_accepted");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(bSocket));
	base::event::notify(_signalGroup.find("event.tcp_socket_accepted")->second, event);
	
	async_accept();
}

std::string BaseTCPServer::str() const
{
	std::stringstream ss;
	ss<<"BaseTCPServer";
	
	return ss.str();
}