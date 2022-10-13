#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <cassert>
#include <boost/function.hpp>
#include <boost/bind.hpp>
//---------------------------------------------------------
struct Base
{
	int m_n;
	Base(int n): m_n(n) { }
	int get() const { return m_n; }
	void set(int n) { m_n=n; }
};
//---------------------------------------------------------
int fct(int n)
{
	return n;
}
//---------------------------------------------------------
int g(boost::function<int (int)> f=0, int n=0)
{
	assert(f!=0);
	return f(n);
}
//---------------------------------------------------------
void run(boost::function<void (void)> f)
{
	f();
}
//---------------------------------------------------------
void run(boost::function<void (void)>* f)
{
	(*f)();
}
//---------------------------------------------------------
void pass()
{
	std::cout<<"passed"<<std::endl;
}
//---------------------------------------------------------
void print()
{
	std::cout<<"print"<<std::endl;
}
//---------------------------------------------------------
int main()
{
	{
		boost::function<void (int)> f=fct; 
		assert(fct(5)==5);
	}
	{
		Base b(0);
		boost::function<void (Base*, int)> set=&Base::set;
		boost::function<int (Base*)> get=&Base::get;
		
		assert(get(&b)==0);
		set(&b, 5);
		assert(get(&b)==5);
	}
	{
		boost::function<void (int)> f; 
		assert(f.empty());
		f=fct;
		assert(!f.empty());
	}
	{
		assert(g(fct, 6)==6);
	}
	{
		boost::function<void (int)> f; 
		try
		{
			f(5);
		}
		catch(const boost::bad_function_call& e)
		{
			assert(f.empty());
		}
	}
	{
		typedef boost::function<void (void)> function_type;
		
		function_type* f=NULL;
	
		f=new function_type();
		*f=pass;
		run(f);
		run(*f);
		//run(pass); //nok
	}
	{
		std::map<std::string, boost::function<void (void)> > map;
		
		map["pass"]=pass;
		map["print"]=print;
	
		map["print"]();
	}
	return 0;
}
