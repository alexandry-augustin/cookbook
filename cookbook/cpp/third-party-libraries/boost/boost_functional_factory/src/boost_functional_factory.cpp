#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/functional/factory.hpp>
#include <boost/functional/value_factory.hpp>

struct Base
{
	Base() //optional
	{
		std::cout<<"[Base::Base]"<<std::endl;
	}
	virtual int get() const=0;
};

struct Sub0: Base
{
	int m_n;
	Sub0(int n):
		Base(),
		m_n(n)
	{
		std::cout<<"[Sub0::Sub0]"<<std::endl;
	}
	/*virtual*/ int get() const
	{
		return m_n;
	}
};

struct Sub1: Base
{
	int m_n;
	Sub1(int n):
		Base(),
		m_n(n)
	{
		std::cout<<"[Sub1::Sub1]"<<std::endl;
	}
	/*virtual*/ int get() const
	{
		return m_n%2;
	}
};

int main()
{
	{
		boost::function<Base* (int)> f=boost::factory<Sub0*>();
		Base* b=f(5);
		assert(b->get()==5);
	}
	{
		typedef boost::function<Base* (int)> foo;
		typedef std::map<std::string, foo> BaseFactory;
		BaseFactory baseFactory;
		baseFactory["sub0"]=boost::factory<Sub0*>();
		baseFactory["sub1"]=boost::factory<Sub1*>();
		Base* b=baseFactory["sub0"](5);
		assert(b->get()==5);
	}
	
	return 0;
}