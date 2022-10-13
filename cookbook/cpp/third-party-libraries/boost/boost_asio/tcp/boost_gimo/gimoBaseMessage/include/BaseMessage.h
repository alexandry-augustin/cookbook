#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H
//---------------------------------------------------------
#include <string>
#include <gimo/BaseDateTime.h>
#include <gimo/BaseTime.h>
//---------------------------------------------------------
namespace base {
class Any;
namespace any {
typedef typename std::vector<base::Any*>	Group;
} //namespace any
} //namespace base
//---------------------------------------------------------
class BaseMessage
{
public:
	enum Direction 
	{
		RECEIVED,
		TRANSMITTED
	};
	enum Sync 
	{
		SYNC,
		ASYNC
	};
	enum Source
	{
		SERIAL,
		TCP
	};
private:
	std::string 			_message;
	BaseMessage::Direction		_direction;
	BaseMessage::Sync		_sync;
	BaseMessage::Source		_source;
	BaseDateTime			_date_time;
	base::any::Group		_arg;
public:
	BaseMessage();
	
	std::string getMessage() const;
	void setMessage(std::string message);
	BaseMessage::Direction getDirection() const;
	void setDirection(BaseMessage::Direction direction);
	BaseMessage::Source getSource() const;
	void setSource(BaseMessage::Source source);
	BaseMessage::Sync getSync() const;
	void setSync(BaseMessage::Sync sync);
	BaseDateTime getDateTime() const;
	void setDateTime(BaseDateTime);
	std::string str() const;
	static std::string str(BaseMessage::Direction direction);
	static std::string str(BaseMessage::Source source);
	static std::string str(BaseMessage::Sync sync);

	base::any::Group* getArgs(); //might be use to store the source socket
};
#endif
