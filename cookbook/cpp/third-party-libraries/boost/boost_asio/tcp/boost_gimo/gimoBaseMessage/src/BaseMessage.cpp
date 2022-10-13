#include "BaseMessage.h"
#include <gimo/Util.h>
#include <gimo/BaseAny.h>
//---------------------------------------------------------
BaseMessage::BaseMessage()
{
}
//---------------------------------------------------------
base::any::Group* BaseMessage::getArgs()
{
	return &_arg;
}
//---------------------------------------------------------
std::string BaseMessage::getMessage() const
{
	return _message;
}
//---------------------------------------------------------
void BaseMessage::setMessage(std::string message)
{
	_message=message;
}
//---------------------------------------------------------
BaseMessage::Source BaseMessage::getSource() const
{
	return _source;
}
//---------------------------------------------------------
void BaseMessage::setSource(BaseMessage::Source source)
{
	_source=source;
}
//---------------------------------------------------------
BaseMessage::Direction BaseMessage::getDirection() const
{
	return _direction;
}
//---------------------------------------------------------
void BaseMessage::setDirection(BaseMessage::Direction direction)
{
	_direction=direction;
}
//---------------------------------------------------------
BaseMessage::Sync BaseMessage::getSync() const
{
	return _sync;
}
//---------------------------------------------------------
void BaseMessage::setSync(BaseMessage::Sync sync)
{
	_sync=sync;
}
//---------------------------------------------------------
BaseDateTime BaseMessage::getDateTime() const
{
	return _date_time;
}
//---------------------------------------------------------
void BaseMessage::setDateTime(BaseDateTime date_time)
{
	_date_time=date_time;
}
//---------------------------------------------------------
std::string BaseMessage::str() const
{
	std::stringstream ss;
	ss<<"[date_time:"<<_date_time.str()<<"] ";
	ss<<"[source:"<<str(_source)<<"] ";
	ss<<"[direction:"<<str(_direction)<<"] ";
	ss<<"[sync:"<<str(_sync)<<"] ";
	ss<<"[raw_message:"<<_message<<"] ";
	ss<<"[raw_lenght:"<<_message.size()<<"] ";
	ss<<"[readable_message:"<<base::readable(_message)<<"] ";
	//if(_socket!=NULL)
	//	ss<<_socket->str();		
	return ss.str();
}
//---------------------------------------------------------
/*static*/ std::string BaseMessage::str(BaseMessage::Direction direction)
{
	std::stringstream ss;
	switch(direction)
	{
	case BaseMessage::RECEIVED:	ss<<"RX"; break;
	case BaseMessage::TRANSMITTED:	ss<<"TX"; break;
	}
	return ss.str();
}
//---------------------------------------------------------
/*static*/ std::string BaseMessage::str(BaseMessage::Source source)
{
	std::stringstream ss;
	switch(source)
	{
	case BaseMessage::TCP:		ss<<"TCP";	break;
	case BaseMessage::SERIAL:	ss<<"SERIAL";	break;
	}
	return ss.str();
}
//---------------------------------------------------------
/*static*/ std::string BaseMessage::str(BaseMessage::Sync sync)
{
	std::stringstream ss;
	switch(sync)
	{
	case BaseMessage::SYNC:	ss<<"SYNC"; break;
	case BaseMessage::ASYNC:ss<<"ASYNC"; break;
	}
	return ss.str();
}
