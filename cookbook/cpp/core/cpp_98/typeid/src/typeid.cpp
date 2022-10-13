#include <iostream>
#include <typeinfo>

int main()
{
	int test;
	std::cout<<typeid(test).name()<<std::endl;

	return 0;
}
