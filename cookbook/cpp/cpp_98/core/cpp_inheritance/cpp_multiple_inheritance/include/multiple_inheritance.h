#include <iostream>
#include <string>
#include <cassert>

// 		A B
// 		\ /
// 		 C

class A
{
	int _a;
public:
	A(int a): _a(a) { std::cout<<"[A::A]"<<std::endl; }
	~A() { std::cout<<"[A::~A]"<<std::endl; }
	void common() { };
	int _get_a() const { return _a; }
	std::string str() { return "[A::str]"; }
};

class B
{
	int _b;
public:
	B(int b): _b(b) { std::cout<<"[B::B]"<<std::endl; }
	~B() { std::cout<<"[B::~B]"<<std::endl; }
	void common() { };
	int get_b() const { return _b; }
	std::string str() { return "[B::str]"; }
};

//the class definition determines the order of construction and destruction, 
//not the member initialization list
class C: public A, public B 
{
	int _c;
public:
	C(): A(0), B(1), _c(0) { std::cout<<"[C::C]"<<std::endl; }
	~C() { std::cout<<"[C::~C]"<<std::endl; }
	int getC() const { return _c; }
	std::string str() { return "[C::str]"; }
};

void multiple_inheritance()
{
	C* c=new C();
	assert(c->_get_a()==0);
	assert(c->get_b()==1);
	
	//c->common(); //error (ambiguitity)
	c->A::common(); //error
	c->B::common(); //error

	A* a=static_cast<A*>(c);
//	std::cout<<a->_get_a()<<std::endl;
//	std::cout<<a->str()<<std::endl;

	B* b=static_cast<B*>(c);
//	std::cout<<b->get_b()<<std::endl;
//	std::cout<<b->str()<<std::endl;

	//delete a;
	delete c;
}
