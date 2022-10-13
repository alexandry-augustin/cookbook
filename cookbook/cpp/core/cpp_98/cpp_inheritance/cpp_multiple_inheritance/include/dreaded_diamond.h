#include <iostream>
#include <string>

// 		 A
//              / \
// 	       B   C
// 		\ /
// 		 D

//specifies a shareable base
class A
{
	int m_a;

public:
	A(int a): m_a(a)
	{
		std::cout<<"[A::A]"<<std::endl;
	}
	~A()
	{
		std::cout<<"[A::~A]"<<std::endl;
	}

	int getA()
	{
		return m_a;
	}
	virtual std::string str()
	{
		return "[A::str]";
	}
};

class B:
	public A
{
	int m_b;

public:
	B(int b): A(0), m_b(b)
	{
		std::cout<<"[B::B]"<<std::endl;
	}
	~B()
	{
		std::cout<<"[B::~B]"<<std::endl;
	}
	int getB()
	{
		return m_b;
	}
	virtual std::string str()
	{
		return "[B::str]";
	}
};

class C:
	public A
{
	int m_c;

public:
	C(int c): A(0), m_c(c)
	{
		std::cout<<"[C::C]"<<std::endl;
	}
	~C()
	{
		std::cout<<"[C::~C]"<<std::endl;
	}
	int getC()
	{
		return m_c;
	}
	virtual std::string str()
	{
		return "[C::str]";
	}
};

class D:
	public B,
	public C
{
	int m_d;

public:
	D(int d): B(0), C(0), m_d(d)
	{
		std::cout<<"[D::D]"<<std::endl;
	}
	~D()
	{
		std::cout<<"[D::~D]"<<std::endl;
	}
	int getD()
	{
		return m_d;
	}
	std::string str()
	{
		return "[D::str]";
	}
};

void dreaded_diamond()
{
	D* d=new D(0);
	std::cout<<d->B::str()<<std::endl;
	
	delete d;
}
