#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <string>
#include <boost/asio.hpp>
#include <gimo/BaseCard.h>
#include <gimo/BaseObserver.h>
#include <gimo/BaseConfiguration.h>
#include "BJUtils.h"

extern BaseConfiguration config; //declared globally in main.cpp

class BaseSubject;
class BaseDeadlineTimer;
class BaseTCPServer;

class ChatServer: public BaseObserver
{
	boost::asio::io_service 		_io_service;
	BaseDeadlineTimer*							_timer;
	BaseTCPServer*						_tcpServer;
	bool							_isAuthenticated;
	bool							_isPongReceived;
	std::string 				_packet_delimiter;

	void tcp_async_write_some(const std::string& message);
	void tcp_write_some(const std::string& message);
	std::string tcp_read_until();
	void tcp_async_read_some();
	void tcp_async_read_until();

public:
	ChatServer(boost::asio::ip::tcp::endpoint& endpoint);
	~ChatServer();

	/*virtual*/ void update(BaseSubject* subject, boost::any* arg);

	bool isAuthenticated() const;
	bool isAuthenticated(bool isAuthenticated);
	bool isPongReceived() const;
	bool isPongReceived(bool isPongReceived);

	void run();
	void stop();
	void closeSocket();
	void accept() const;
};

#endif
