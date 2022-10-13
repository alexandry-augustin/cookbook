#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <boost/date_time.hpp>
#include <boost/regex.hpp>
//---------------------------------------------------------
std::string str(const boost::posix_time::ptime& ptime) //HH:MM:SS 
{
	if(ptime.is_not_a_date_time())
		return "N/A";
	
	int hours=ptime.time_of_day().hours();
	int mins=ptime.time_of_day().minutes();
	int secs=ptime.time_of_day().seconds();

	std::stringstream ss;
//	boost::posix_time::to_simple_string(_time);
	ss<<(hours<10?"0":"")<<hours<<":";
	ss<<(mins<10?"0":"")<<mins<<":";
	ss<<(secs<10?"0":"")<<secs;

	return ss.str();
}
//---------------------------------------------------------
int main()
{
	{
		boost::gregorian::date date(2010, 1, 30); 
		assert(date.year()==2010);
		//assert(date.month()=="Jan");
		assert(date.day()==30);
		//assert(date.day_of_week()=="Sat");
		//assert(date.end_of_month()=="2010-Jan-31");
	}
/*	{
		boost::gregorian::date today;
		std::string today_str;
		
		assert(today.is_not_a_date());
		today=boost::gregorian::day_clock::universal_day();
		today=boost::gregorian::day_clock::local_day();
		assert(!today.is_not_a_date());
		today_str=boost::gregorian::to_iso_extended_string(today); //YYYY-MM-DD
		assert(boost::regex_match(today_str,
			boost::regex("(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])")));
		today=boost::gregorian::from_string(today_str);
	}
	{
		boost::posix_time::ptime now;
		std::string now_str;
		
		assert(now.is_not_a_date_time());
		now=boost::posix_time::not_a_date_time;
		now=boost::posix_time::microsec_clock::local_time();
		now=boost::posix_time::microsec_clock::universal_time(); //necessary for _timer.expires_at(...)
		now=boost::posix_time::time_from_string(now_str);
		now=boost::posix_time::time_from_string(
			boost::gregorian::to_iso_extended_string(now.date())
			+std::string(" ")+now_str);

		int hours=now.time_of_day().hours();
		int mins=now.time_of_day().minutes();
		int secs=now.time_of_day().seconds();

		assert(boost::regex_match(now_str, boost::regex("(([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9]")));
		assert(boost::regex_match(now_str,
			boost::regex("(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01]) (([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9]")));
	}
	*/
	{
		std::string time_str("2012-01-21 10:21:01");
		assert(boost::regex_match(time_str,
			boost::regex("(19|20)\\d\\d[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01]) (([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9]")));
		boost::posix_time::ptime ptime=boost::posix_time::time_from_string(time_str);
		assert(str(ptime)=="10:21:01");
	}
	{
		std::string time_str("10:21:01");
		assert(boost::regex_match(time_str, boost::regex("(([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9]")));
		boost::posix_time::ptime now=boost::posix_time::microsec_clock::local_time();
		boost::posix_time::ptime ptime=
			boost::posix_time::time_from_string(boost::gregorian::to_iso_extended_string(now.date())+std::string(" ")+time_str);
		assert(str(ptime)=="10:21:01");
	}
	{
		boost::posix_time::time_duration time_duration(boost::posix_time::not_a_date_time);
		assert(time_duration.is_not_a_date_time());
	}
	{
		boost::posix_time::time_duration time_duration(boost::posix_time::seconds(5));
	}
	{
		//year, month, day from epoc
		boost::posix_time::ptime ptime(boost::posix_time::from_time_t(1311567843)); //from epoc
		boost::gregorian::date date=ptime.date();
		assert(date.year()==2011);
		assert(date.day()==25);
		assert((int)date.month()==7);
	}
	{
		//year, month, day, time from epoc
		boost::posix_time::ptime ptime(boost::posix_time::from_time_t(1407380400000000000/1000000000)); //epoc in ns
		assert(boost::posix_time::to_simple_string(ptime)=="2014-Aug-07 03:00:00");
	}
	return 0;
}
