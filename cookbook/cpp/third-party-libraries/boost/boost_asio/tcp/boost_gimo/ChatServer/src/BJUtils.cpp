#include "BJUtils.h"
#include <string.h>	//strerror
#include <errno.h>	//errno
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <boost/thread.hpp>
#include <boost/regex.hpp>
#include <boost/date_time.hpp>

namespace gimo
{
	bool isValidDateTimeStamp(const std::string& str)
	{
		static const boost::regex expression("(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])_\\d{2}:[0-5]\\d:[0-5]\\d");
		return boost::regex_match(str, expression);
	}
	
	bool isValidPingTimout(const std::string& str)
	{
		static const boost::regex expression("PINGTIMEOUT\\d*");
		return boost::regex_match(str, expression);
	}
	
	int toCardIndex(int cardCode)
	{
		static int cardCodeFromShoe[52]={ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 14, 41, 42, 43, 44,
				45, 46, 47, 48, 49, 50, 51, 52, 40, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
				38, 39, 27, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1 };
		static int cardIndex[52]={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
				19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
				39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

		int* index=std::find(cardCodeFromShoe, cardCodeFromShoe+52, cardCode);
		if(index==NULL)
			return -1;

		return cardIndex[index-cardCodeFromShoe];
	}
	
	bool processCard(const std::string& str, int& cardIndex, std::string& timeStamp)
	{
		if(!isValidCard(str))
			return false;

		size_t at=str.find('@');
		cardIndex=toCardIndex(atoi(str.substr(1, at-1).c_str())); //first character being '#'
		//card=atoi(str.substr(1, at-1).c_str()); //first character being '#'
		timeStamp=str.substr(at+1);

		return true;
	}
	
	bool isValidTimeCode(const std::string& str)
	{
		static const boost::regex expression("\\d{2}:[0-5]\\d:[0-5]\\d");
		return boost::regex_match(str, expression);
	}
	
	bool isValidDateTimeCode(const std::string& str)
	{
		static const boost::regex expression("(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])_\\d{2}:[0-5]\\d:[0-5]\\d");
		return boost::regex_match(str, expression);
	}
	
	bool isValidCard(const std::string& str)
	{
	/*	size_t pos=str.find("@");
		if(pos==std::string::npos)
			return false;

		if(!isValideDateTimeStamp(str.substr(pos)))
			return false;
	*/
		static const boost::regex expression("#\\d{2}@(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])_\\d{2}:[0-5]\\d:[0-5]\\d");
		return boost::regex_match(str, expression);
	}
	
	bool isValidCardRequest(const std::string& str)
	{
		static const boost::regex expression("CARD\\d*");
		return boost::regex_match(str, expression);
	}
	
	bool isValidSeatingRequest(const std::string& str)
	{
		static const boost::regex expression("13 \\d*");
		return boost::regex_match(str, expression);
	}
	
	bool isValidUnseatingRequest(const std::string& str)
	{
		static const boost::regex expression("14 \\d*");
		return boost::regex_match(str, expression);
	}
	
	bool isValidChatRequest(const std::string& str)
	{
		static const boost::regex expression("100 .*");
		return boost::regex_match(str, expression);
	}
	
	bool isValidBetRequest(const std::string& str)
	{
		static const boost::regex expression("3 \\d{1}:[0:7] \\d*");
		return boost::regex_match(str, expression);
	}
	
	bool isValidTipRequest(const std::string& str)
	{
		static const boost::regex expression("15 \\d*");
		return boost::regex_match(str, expression);
	}
	
}
