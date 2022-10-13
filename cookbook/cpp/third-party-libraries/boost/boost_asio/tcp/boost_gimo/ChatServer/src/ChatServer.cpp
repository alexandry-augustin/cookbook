#include "ChatServer.h"
#include <boost/thread.hpp>
#include <gimo/BaseSubject.h>
#include <gimo/BaseTCPServer.h>
#include <gimo/BaseDeadlineTimer.h>
#include <gimo/BaseMessage.h>

ChatServer::ChatServer(boost::asio::ip::tcp::endpoint& endpoint)
	: _isAuthenticated(false), _isPongReceived(false)
{
	_tcpServer=new BaseTCPServer(_io_service, endpoint);
	_packet_delimiter=gimo::to_string(config.get<std::string>("Common", "packetDelimiter"), ",");
	_tcpServer->setPacketDelimiter(_packet_delimiter);
	_tcpServer->registerObserver(this);

	_timer=new BaseDeadlineTimer("chat.server.ping", _io_service);
	_timer->setTimeoutStr(config.get<std::string>("Common", "readTimeoutStr"));
	_timer->registerObserver(this);
}

ChatServer::~ChatServer()
{
	if(_timer!=NULL)
	{
		delete _timer;
		_timer=NULL;
	}
	if(_tcpServer!=NULL)
	{
		delete _tcpServer;
		_tcpServer=NULL;
	}
}

/*virtual*/ void ChatServer::update(BaseSubject* subject, boost::any* arg)
{
	assert(subject!=NULL);
	
/*	if(subject==_timer)
	{
		assert(gimo::contains<std::string>(*arg));
		std::string message=boost::any_cast<std::string>(*arg);
		
		if(config.get<bool>("Common", "enablePing") && message==config.get<std::string>("Common", "readTimeoutStr"))
		{
			if(isPongReceived())
			{
				_timer->start(); //re-start ping timer
				tcp_async_write_some(config.get<std::string>("Common", "pingMessage")); //send a new ping
				isPongReceived(false);
				return;
			}
			
			if(!isPongReceived())
			{
				std::cout<<"[ChatServer::update] Shoe not responding to PING messages."<<std::endl;
				std::cout<<"[ChatServer::update] Shoe disconnected."<<std::endl;
				//stop();
				closeSocket();
				accept();
			}
		}
		else
			std::cout<<"[ChatServer::update] Message discarded ["<<message<<"]."<<std::endl;
		
		return;
	}	
	
	assert(gimo::contains<BaseMessage>(*arg));
	BaseMessage message=boost::any_cast<BaseMessage>(*arg);
	std::string cleanMessage=gimo::clean(message.getMessage());
	
	//display the received message
	bool display=true;
	if(cleanMessage==config.get<std::string>("Common", "pingMessage") && !config.get<bool>("Server", "displayPingMessages"))
		display=false;
	if(cleanMessage==config.get<std::string>("Common", "pongMessage") && !config.get<bool>("Server", "displayPingMessages"))
		display=false;
	if(display)
		std::cout<<message.str()<<std::endl;
	
	if(subject==_tcpServer)
	{
		if(cleanMessage=="accepted")
		{
			std::cout<<"[ChatServer::update] Shoe accepted by TCPServer."<<std::endl;
			std::cout<<"[ChatServer::update] Waiting for authentication message..."<<std::endl;
			//Read connection string
			tcp_async_read_until();
		}
		//Authenticate shoe
		if(cleanMessage==config.get<std::string>("Common", "authenticationStr"))
		{
			std::cout<<"[ChatServer::update] Shoe authenticated."<<std::endl;
			isAuthenticated(true);

			//send ack
			tcp_async_write_some(config.get<std::string>("Common", "pingTimeoutPrefix")+config.get<std::string>("Common", "pingTimeout"));

			//request a card
			boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
			requestCard(config.get<int>("Common", "readTimeout"));

			//trigger ping messages
			boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
			if(config.get<bool>("Common", "enablePing"))
			{
				_timer->start(config.get<int>("Client", "pingLatencyMult")*config.get<int>("Common", "pingTimeout"));
				tcp_async_write_some(config.get<std::string>("Common", "pingMessage"));
				isPongReceived(false);
			}
		}
		//when a timeout notification is received from the shoe client, re-send a card request to the shoe client
		if(cleanMessage==config.get<std::string>("Common", "readTimeoutStr"))
		{
			std::cout<<"[ChatServer::update] Timeout. Shoe client failed to get a card."<<std::endl;
			requestCard(config.get<int>("Common", "readTimeout")); //request a new card
		}
		if(cleanMessage==config.get<std::string>("Common", "pongMessage"))
			isPongReceived(true);
		if(!isAuthenticated() && cleanMessage!=config.get<std::string>("Common", "pongMessage") && cleanMessage!="accepted")
		{
			std::cout<<"[ChatServer::update] Shoe not authenticated."<<std::endl;
			std::cout<<"[ChatServer::update] Message discarded: "<<std::endl;
			std::cout<<"\t[ChatServer::update] "<<message.str()<<std::endl;
			std::cout<<"[ChatServer::update] Waiting for authentication message..."<<std::endl;
		}
	}*/
}

void ChatServer::closeSocket()
{
	std::cout<<"[ChatServer::closeSocket] Closing Socket..."<<std::flush;
	try
	{
		_tcpServer->closeSocket();
	}
	catch(const std::exception& e)
	{
		std::cout<<"[nok]"<<std::endl;
		return;
	}
	std::cout<<"[ok]"<<std::endl;
}

void ChatServer::run()
{
	std::cout<<"[ChatServer::run] Chat server is listening on ["<<_tcpServer->getEndpoint().address().to_string()<<":"<<_tcpServer->getEndpoint().port()<<"] ..."<<std::endl;
	//maintains io_service "busy" so io_service.run() remains blocking when no tasks are being performed
	boost::asio::io_service::work work(_io_service);
	_io_service.run();
	std::cout<<"[ChatServer::run] Chat server is stopped."<<std::endl;
}

void ChatServer::stop()
{
	std::cout<<"[ChatServer::stop] Stopping io_service..."<<std::endl;
	_io_service.stop();
}

bool ChatServer::isAuthenticated() const
{
	return _isAuthenticated;
}

bool ChatServer::isAuthenticated(bool isAuthenticated)
{
	_isAuthenticated=isAuthenticated;
}

bool ChatServer::isPongReceived() const
{
	return _isPongReceived;
}

bool ChatServer::isPongReceived(bool isPongReceived)
{
	_isPongReceived=isPongReceived;
}

void ChatServer::accept() const
{
	assert(_tcpServer!=NULL);

	_tcpServer->accept(); //async
}

void ChatServer::tcp_async_write_some(const std::string& message)
{
	assert(_tcpServer!=NULL);
	
	_tcpServer->async_write_some(message);
}

void ChatServer::tcp_write_some(const std::string& message)
{
	assert(_tcpServer!=NULL);

	_tcpServer->write_some(message);
}

std::string ChatServer::tcp_read_until()
{
	assert(_tcpServer!=NULL);

	return _tcpServer->read_until();
}

void ChatServer::tcp_async_read_some()
{
	assert(_tcpServer!=NULL);
	
	_tcpServer->async_read_some();
}

void ChatServer::tcp_async_read_until()
{
	assert(_tcpServer!=NULL);
	
	_tcpServer->async_read_until();
}

