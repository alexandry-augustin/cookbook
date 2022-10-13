#ifndef BJUTILS_H
#define BJUTILS_H

#include <gimo/Utils.h> //avoid multiple inclusions throughout in the BJ project
//#include <gimo/BaseDeadlineTimer.h>
//#include "BJDeadlineTimer.h"

namespace gimo
{
	bool isValidPingTimout(const std::string& str);
	bool isValidDateTimeStamp(const std::string& str);
	bool isValidTimeCode(const std::string& str);
	bool isValidDateTimeCode(const std::string& str);
	bool isValidSeatingRequest(const std::string& str);
	bool isValidUnseatingRequest(const std::string& str);
	bool isValidBetRequest(const std::string& str);
	bool isValidCard(const std::string& str);
	bool isValidCardRequest(const std::string& str);
	bool isValidChatRequest(const std::string& str);
	bool isValidTipRequest(const std::string& str);
	
	int toCardIndex(int cardCode);
	bool processCard(const std::string& str, int& cardIndex, std::string& timeStamp);
	
	template <typename T>
	bool contains(const boost::any& any)
	{
		return typeid(T)==any.type();
	}
	
	//template specialization from Utils.h
	/*template <>
	inline std::string gimo::to_string(const boost::any& any)
	{
		if(gimo::contains<std::string>(any))
			return boost::any_cast<std::string>(any);

		std::stringstream ss;
		if(gimo::contains<BaseDeadlineTimer*>(any))
		{
				BaseDeadlineTimer* timer=boost::any_cast<BaseDeadlineTimer*>(any);
				ss<<timer->str();
		}
		if(gimo::contains<BJDeadlineTimer*>(any))
		{
				BJDeadlineTimer* timer=boost::any_cast<BJDeadlineTimer*>(any);
				ss<<timer->str();
		}

		return ss.str();
	}*/
}

#endif
