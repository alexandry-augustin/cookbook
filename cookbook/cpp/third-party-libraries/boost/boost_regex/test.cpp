#include <string>
#include <map>
#include <iostream>
#include <gimo/BaseClockTimer.h>
#include <gimo/Utils.h>
#include <boost/any.hpp>
#include <boost/regex.hpp>
//#include <boost/asio.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <gimo/BaseMessage.h>
#include "test.h"

using namespace std;

namespace test
{
	int f() { return 5; }
}

class base
{

public:
	int u;
	base(): u(5) { }
	base(const base& v) { u=v.u; }
	//~base() { cout<<"des"<<endl; }
	std::string str() const
	{
		std::stringstream ss;
		ss<<u;

		return ss.str(); 
	}
};

class sub: public base
{

};

void notify2(boost::any* arg)
{
    std::string str_;
	try
	{
		str_=boost::any_cast<std::string>(*arg);
	}
	catch(const std::exception& e)
	{
		std::cout<<"Exception_: "<<e.what()<<std::endl;
	}
	std::cout<<str_<<std::endl;
}

void notify(boost::any* arg)
{
	notify2(arg);
}


int& fct()
{
	int a=9;
	return a;
}

int main()
{
	base* p(new base());
	std::cout<<(p->str())<<std::endl;

//	boost::asio::io_service                _io_service;
	

//	cout<<gimo::isalnum_ext('~')<<endl;

	/*std::string str("a\n\t");
	str+=char(0x00);
	str+=char(0x19);
	str+=char(0x0a);
	str+=char('b');
	str+=char(0x19);
gimo::format(str);
	std::cout<<gimo::readable(str)<<std::endl;*/
/*
	std::string str("abc");
	str.insert(2, "x");
	std::cout<<str<<std::endl; //abxc
*/
/*
	char c=char(0x30);
	std::string str("1234");
	str+="test";
	str+="5678";
	str+="test";

	std::cout<<str<<std::endl;

	std::vector<std::string> v=gimo::split(str, "tet");

	std::cout<<v.size()<<std::endl;
	for(int i=0; i<v.size(); ++i)
		std::cout<<"["<<v[i]<<"]"<<std::endl;*/



	/*BaseMessage bMessage;
	bMessage.setTime(now());
	bMessage.setMessage("test\n\t\r");
	bMessage.setDirection(BaseMessage::RECEIVED);
	bMessage.setSync(BaseMessage::SYNC);
	bMessage.setSource(BaseMessage::TCP);
	std::cout<<bMessage.str()<<std::endl;*/

    /*boost::any* arg=new boost::any(std::string("timed_out"));
    notify(arg);*/
/*
	base* timer=new base();
	boost::any* any=new boost::any(timer);

	base* timer_=NULL;
    try
    {
    	timer_=boost::any_cast<base*>(*any);
    }
    catch(const std::exception& e)
    {
    	std::cout<<e.what()<<std::endl;
    }
    std::cout<<timer_->u<<std::endl;
*/
/*
	base* pData=new base();
	boost::any* any=new boost::any(*pData);   //create a copy
	base* pData_recovered=new base();
	try
	{
		*pData_recovered=boost::any_cast<base>(*any);
	}
    catch(const boost::bad_any_cast& e)
    {
    	std::cout<<e.what()<<std::endl;
    }

    delete pData;
    delete any;

	std::cout<<pData_recovered->u<<std::endl;
*/
	/*int t=5;

	BaseClockTimer c(100, "test");
	c.start();
	sleep(t);
	c.pause();
	sleep(t);
	c.resume();
	sleep(t);
	c.pause();
	sleep(t);
	c.resume();
	sleep(t);

	c.restart();
	sleep(t);

	cout<<c.str()<<endl;
	c.stop();
	cout<<c.str()<<endl;*/
}
