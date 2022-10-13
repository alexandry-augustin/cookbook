#ifndef PING_H
#define PING_H

//move in socket
class BaseDeadlineTimer;
class Ping
{
// pingMessage=PING
// pongMessage=PONG
// pingTimeoutPrefix=PINGTIMEOUT
bool				_isPongReceived;
BaseDeadlineTimer*		_timer;
//	boost::thread ping=boost::thread(&Facade::displayTimeout, this);
//base::Xml* pingXml() const;
//base::Xml* pongXml() const;
//base::Xml* pingTimeoutXml() const;
//	if(message==_configuration->get<std::string>("Common", "pingMessage") && !_configuration->get<bool>("Server", "displayPingMessages"))
//		display=false;
//	if(message==_configuration->get<std::string>("Common", "pongMessage") && !_configuration->get<bool>("Server", "displayPingMessages"))
//		display=false;
	/*
	if(base::isValid(bMessage.getMessage(), "ping")
		&& _configuration->get<bool>("Common", "enablePing")
		&& _configuration->get<bool>("Client", "respondToPing"))
	{
		_tcpClient->getSocket()->async_write_some(pongXml()->data());
		return;
	}*/
/*
base::Xml* Facade::pongXml() const
{
	base::Xml* xml_message=new base::Xml();
	xml_message->ptree()->put("data.ping.pong", "");
	
	return xml_message;
}*/
/*
base::Xml* Facade::pingTimeoutXml() const
{
	base::Xml* xml_message=new base::Xml();
	xml_message->ptree()->put("data.ping.timeout",_configuration->get<std::string>("Common", "pingTimeout"));
	_bSocket->async_write_some(xml_message->data());
	
	return xml_message;
}*/
/*
base::Xml* Facade::pingXml() const
{
	base::Xml* xml_message=new base::Xml();
	xml_message->ptree()->put("data.ping.ping", "");
	
	return xml_message;
}*/
/*
	if(_configuration->get<bool>("Common", "enablePing")
		&& message=="TO")
	{
		if(_isPongReceived)
		{
			_timer->start(); //re-start ping timer
			
			_bSocket->async_write_some(pingXml()->data());
			
			_isPongReceived=false;
			
			return;
		}
		
		if(!_isPongReceived)
		{
			std::cout<<"[Server::handleTimeout] Shoe not responding to PING messages."<<std::endl;
			
			try
			{
				_bSocket->close();
			}
			catch(const std::exception& e)
			{
				assert(false);
			}
			
			std::cout<<"[Server::handleTimeout] Shoe disconnected."<<std::endl;
			
			_tcpServer->async_accept();
			
			return;
		}
	}*/

		/*
		//trigger ping messages
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		if(_configuration->get<bool>("Common", "enablePing"))
		{
			_timer->start(_configuration->get<int>("Client", "pingLatencyMult")*_configuration->get<int>("Common", "pingTimeout"));
			
			_bSocket->async_write_some(pingXml()->data());
			
			_isPongReceived=false;
		}*/
	/*
	if(type=="ping")
	{
		_isPongReceived=true;
		
		return;
	}*/
}

#endif
