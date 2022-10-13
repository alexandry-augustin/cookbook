#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

int add(int x, int y)
{
	return x+y; 
}

int mult(int x, int y)
{
	return x*y; 
}

int compute(int (*fct)(int, int), int x, int y)
{
	return fct(x, y); 
}

class base_00
{
public:
	typedef int (base_00::*fct_t)(int, int);
private:
	int (base_00::*_ptr)(int, int); //or fct_t _ptr;
public:
	base_00(): _ptr(/*&base_00::add*/NULL) { }

//	void set_fct(fct_t fct)
//or
	void set_fct(int (base_00::*fct)(int, int)) { _ptr=fct; }
	int compute(int a, int b) { return (*this.*_ptr)(a, b); }
//	int compute(fct_t ptr, int a, int b)
//or
	int compute(int (base_00::*ptr)(int, int), int a, int b) { return (*this.*ptr)(a, b); }
	int mult(int a, int b) { return a*b; }
	int add(int a, int b) { return a+b; }
};

struct base_01
{
	base_01(int n): _n(n)
	{
	}

	int _n;
};

namespace base_00_ns {
class base_00
{
	int _n;
public:
	base_00(int n): _n(n) { }
	std::string str() const
	{
		std::ostringstream oss;
		oss<<_n;
		return oss.str();
	}
};
} //namespace base_00_ns

//typedef std::string (base_00_ns::*base_00_ptr)() const;
typedef std::string (base_00_ns::base_00::*base_00_ptr)() const;

int main()
{
	{
		int (*p)(int, int); //pointer to a function that returns an int and takes a 2 int parameters.
		p=add; //or ptr=&add
		std::cout<<"::add:"<<compute(p, 5, 5)<<std::endl;
		p=mult; //or ptr=&mult
		std::cout<<"::mult:"<<compute(p, 5, 5)<<std::endl;
	}
	{
		base_00 c;
		int (base_00::*ptr3)(int, int); //or base_00::fct_t ptr3;
	
		ptr3=&base_00::add;
		assert((c.*ptr3)(1, 1)==2);
		//or
		base_00* p3=&c;
		assert((p3->*ptr3)(3, 3)==6);
	}
	{
		base_00 c;
		int (base_00::*ptr3)(int, int); //or base_00::fct_t ptr3;

		ptr3=&base_00::add;
		c.set_fct(ptr3);
		assert(c.compute(1, 2)==3);

		ptr3=&base_00::mult;
		c.set_fct(ptr3);
		assert(c.compute(1, 2)==2);
	}
	{	
		base_00 c;
		int (base_00::*ptr3)(int, int); //or base_00::fct_t ptr3;

		ptr3=&base_00::add;
		assert(c.compute(ptr3, 1, 2)==3);

		ptr3=&base_00::mult;
		assert(c.compute(ptr3, 1, 2)==2);
	}
	{
		base_01 e(4);
		int base_01::*ptr1; //pointer to class member data
	
		ptr1=&base_01::_n;
		assert(e.*ptr1==4);
		//or
		base_01* p1=&e;
		assert(p1->*ptr1==4);
	}
	/*{
		base_00* b=new base_00(5);
		//base_00_ptr p;
		//or
		std::string (base_00::*p)() const;
		
		p=&base_00::str;
		assert((*b.*p)()=="5");
	}*/
	{
		base_00_ns::base_00* b=new base_00_ns::base_00(5);
		base_00_ptr p;
		//or
		//std::string (base_00::base_00::*p)() const;
		
		p=&base_00_ns::base_00::str;
		assert((*b.*p)()=="5");
	}
	return 0;
}
