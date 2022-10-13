#include<iostream>

//volatile prevent the compiler from applying any optimizations on code
//that assume values of variables cannot change "on their own."

class base
{
public:
	void str()
	{
		std::cout<<"Str"<<std::endl;
	}
	void str() const
	{
		std::cout<<"const Str"<<std::endl;
	}
	void str() volatile
	{
		std::cout<<"volatile Str"<<std::endl;
	}
	void str() const volatile
	{
		std::cout<<"const volatile Str"<<std::endl;
	}
};

static int foo;
void bar(void)
{
	foo=0;
	while(foo!=255)
		;
}
//as optimzed by the compiler
//volatile prevent this as foo might represent a location that can be
//changed by other elements of the computer system at any time, such as
//a hardware register of a device connected to the CPU
//void bar_optimized(void)
//{
//	foo=0;
//	while(true);
//}

int main()
{
	base b;
	b.str();
	return 0;
}
