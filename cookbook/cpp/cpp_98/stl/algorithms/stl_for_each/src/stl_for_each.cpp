#include <iostream>
#include <algorithm> //std::for_each
#include <vector>
#include <string>
#include <functional> //bind2nd mem_fun mem_fun_ref

void fct(int i)
{
	std::cout<<i<<" ";
}

struct Fct
{
	void operator()(int i)
	{
		std::cout<<i<<" ";
	}
};

struct base
{
	virtual void f() const=0;
};

struct A: public base
{
	void f() const
	{
		std::cout<<"A::f"<<std::endl;
	}
};

struct B: public base
{
	void f() const
	{
		std::cout<<"B::f"<<std::endl;
	}
};

struct myClass
{
	int m_a;

public:
	myClass(int a=0):
		m_a(a)
	{
	}

	void print() const
	{
		std::cout<<m_a<<std::endl;
	}
	void printInt(int a) const
	{
		std::cout<<a<<std::endl;
	}
	void printString(std::string s) const
	{
		std::cout<<s<<std::endl;
	}
	void print_()
	{
		int a[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //arguments for print(int a)
		std::vector<int> v(a, a+10);
		std::for_each(v.begin(), v.end(), bind1st(std::mem_fun(&myClass::printInt), this));
	}
};

int main() 
{
	{
		int a[3]={ 4, 6, 2 };
		std::for_each(a, a+3, fct);
		std::cout<<std::endl;
	}
	{
		int a[3]={ 4, 6, 2 };
		std::vector<int> v(a, a+3);
		Fct Fct_obj;

		std::for_each(v.begin(), v.end(), fct);
		std::cout<<std::endl;
		// or:
		std::for_each(v.begin(), v.end(), Fct_obj);
		std::cout<<std::endl;
	}
	{
		int a[3]={ 4, 6, 2 };
		std::vector<int> v(a, a+3);
		std::vector<base*> u;
		u.push_back(new A());
		u.push_back(new B());

		std::for_each(u.begin(), u.end(), std::mem_fun(&base::f));
	}
	
	/*std::vector<base> t;
	  t.push_back(A());
	  t.push_back(B());

	  std::std::for_each(u.begin(), u.end(), mem_fun(&base::f));*/
	// http://www.java2s.com/Code/Cpp/Vector/Callmemberfunctionforeachelementinvector.htm
	
	{
		std::vector<myClass> z(5);
		std::for_each(z.begin(), z.end(), std::mem_fun_ref(&myClass::print));
		std::for_each(z.begin(), z.end(), std::bind2nd(mem_fun_ref(&myClass::printString), "some text"));
	}
	{
		std::vector<myClass*> y;
		y.push_back(new myClass(5));
		std::for_each(y.begin(), y.end(), std::mem_fun(&myClass::print));
		std::for_each(y.begin(), y.end(), std::bind2nd(mem_fun(&myClass::printString), "some text"));
	}
	{
		myClass c;
		c.print_();
	}
	return 0;
}

/*
#include <algorithm>

class A
{
public:
void print(int v) { std::std::cout<<v<<std::std::endl; }

void load()
{
int a[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //arguments for print()
std::vector<int> v(a, a+10);
std::std::for_each(v.begin(), v.end(), std::bind1st(std::mem_fun(&A::print), this));
}
};

void main()
{
A a;
a.load();
}*/
