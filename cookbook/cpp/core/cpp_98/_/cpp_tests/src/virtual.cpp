#include <cassert>
#include <iostream>

class base_00
{
public:
	base_00()
	{
		std::cout<<"[base_00::base_00]"<<std::endl;
		std::cout<<id()<<std::endl;
	}
	virtual ~base_00()
	{
		std::cout<<"[base_00::~base_00]"<<std::endl;
	}
	virtual int id() const
	{
		return 0;
	}
};

class base_01: public base_00
{
public:
	base_01()
	{
		std::cout<<"[base_01::base_01]"<<std::endl;
	}
	/*virtual*/ ~base_01()
	{
		std::cout<<"[base_01::~base_01]"<<std::endl;
	}
	/*virtual*/ int id() const
	{
		return 1;
	}
};

class base_02: public base_01
{
public:
	base_02()
	{
		std::cout<<"[base_02::base_02]"<<std::endl;
	}
	/*virtual*/ ~base_02()
	{
		std::cout<<"[base_02::~base_02]"<<std::endl;
	}
	/*virtual*/ int id() const
	{
		return 2;
	}
};

int main(int argc, char* argv[])
{
	{
		base_01* p=new base_01();
		//std::cout<<p->id()<<std::endl;
		delete p;
	}
}
