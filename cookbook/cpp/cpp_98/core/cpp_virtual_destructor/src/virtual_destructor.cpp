#include <iostream>
#include <string>
#include <cassert>

// virtual destructors are useful when you can delete an instance of
// a derived class through a pointer to base_00 class

struct base_00
{
	base_00() { std::cout<<"[base_00::base_00]"<<std::endl; }
	virtual ~base_00() { std::cout<<"[base_00::~base_00]"<<std::endl; }
	virtual unsigned int id() const { return 0; }
};

struct base_01: public base_00
{
	base_01() { std::cout<<"[base_01::base_01]"<<std::endl; }
	/*virtual*/ ~base_01() { std::cout<<"[base_01::~base_01]"<<std::endl; }
	/*virtual*/ unsigned int id() const { return 1; }
};

struct base_02
{
	base_02() { std::cout<<"[base_02::base_02]"<<std::endl; }
	~base_02() { std::cout<<"[base_02::~base_02]"<<std::endl; }
	unsigned int id() const { return 2; }
};

struct base_03: public base_02
{
	base_03() { std::cout<<"[base_03::base_03]"<<std::endl; }
	~base_03() { std::cout<<"[base_03::~base_03]"<<std::endl; }
	unsigned int id() const { return 3; }
};

class base_10
{
	virtual ~base_10()=0;
};
inline base_10::~base_10()
{
	std::cout<<"[base_10::base_10]"<<std::endl;
}

void test_virtual()
{
	{
		base_00* b=new base_01();	
		//[base_00::base_00]
		//[base_01::base_01]

		assert(b->id()==1);

		delete b;
		//[base_01::~base_01]
		//[base_00::~base_00]
	}
	{
		base_01* b=new base_01();	
		//[base_00::base_00]
		//[base_01::base_01]

		assert(b->id()==1);

		delete b;
		//[base_01::~base_01]
		//[base_00::~base_00]
	}
}

void test_non_virtual()
{
	{
		base_02* b=new base_03();	
		//[base_02::base_02]
		//[base_03::base_03]

		assert(b->id()==2);

		delete b;
		//[base_02::~base_02]
		// !!! ~base_03 not called !!!
	}
	{
		base_03* b=new base_03();	
		//[base_02::base_02]
		//[base_03::base_03]

		assert(b->id()==3);

		delete b;
		//[base_03::~base_03]
		//[base_02::~base_02]
	}
}

void test_misc()
{
	{
		//base_10 b;
	}
}

int main()
{
	test_virtual();
	test_non_virtual();
	test_misc();
	return 0;
}
