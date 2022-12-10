#include <iostream>
#include <string>

//static_cast: type conversions at compile time

class Base
{
public:
	virtual std::string str()
	{
		return "[Base::Base]";
	}
};

class Sub: public Base
{
public:
	/*virtual*/ std::string str()
	{
		return "[Sub::Sub]";
	}
};

int main()
{
	{	
		int n=static_cast<int>(float(5.8));
		std::cout<<n<<std::endl;

		void* m=static_cast<void*>(new int(9));
		std::cout<<(*static_cast<int*>(m))<<std::endl;

		Base* s=new Sub();
		std::cout<<static_cast<Sub*>(s)->str()<<std::endl;
	}
	return 0;
}
