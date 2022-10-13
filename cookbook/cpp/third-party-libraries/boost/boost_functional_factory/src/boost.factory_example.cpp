#include <map>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/functional/factory.hpp>

struct Base
{
	std::string name;
	Base(std::string name)
		: name(name)
	{ }
	virtual ~Base()
	{
		std::cout << "Good bye, " << name << "\n";
	}
	virtual void stuff()
	{
		std::cout << "Name: " << name << "\n";
	}
};

typedef boost::shared_ptr<Base> BasePtr;

struct ChildA : public Base
{
	ChildA(std::string name)
		: Base(name)
	{ }
	void stuff()
	{
		Base::stuff();
		std::cout << "Child A\n";
	}
};

typedef boost::shared_ptr<ChildA> ChildAPtr;

struct ChildB : public Base
{
	int apples;
	ChildB(std::string name, int apples = 12)
		: Base(name), apples(apples)
	{
	}
	void stuff()
	{
		Base::stuff();
		std::cout << "Child B has " << apples << " apples\n";
	}
};

typedef boost::shared_ptr<ChildB> ChildBPtr;

namespace boost {
	// Add in a simple wrapper for a factor creating shared pointers
		template<typename T>
	struct shared_factory : public factory<shared_ptr<T> >
	{ };
}

int _main(int argc, char **argv)
{
	typedef boost::function<BasePtr (std::string name)> Factory;
	typedef std::map<std::string, Factory> FactoryMap;
	
	FactoryMap factoryMap;
	factoryMap["a"] = boost::shared_factory<ChildA>();
	factoryMap["b"] = boost::shared_factory<ChildB>();
	// http://stackoverflow.com/questions/1335301/using-boostbind-with-a-constructor
	factoryMap["b_overload"] = boost::bind(boost::shared_factory<ChildB>(), _1, 6);
	
	BasePtr test = factoryMap["a"]("Test1");
	test->stuff();
	
	std::cout << "\nNew object in same pointer (dtor)\n\n";
	test = factoryMap["b"]("Test2");
	test->stuff();
	
	std::cout << "\nOverloading bound apples to 6 (default was 12)\n\n";
	test = factoryMap["b_overload"]("Test3");
	test->stuff();
	
	return 0;
}

/*
Name: Test1
Child A

New object in same pointer (dtor)

Good bye, Test1
Name: Test2
Child B has 12 apples

Overloading bound apples to 6 (default was 12)

Good bye, Test2
Name: Test3
Child B has 6 apples
Good bye, Test3
*/
