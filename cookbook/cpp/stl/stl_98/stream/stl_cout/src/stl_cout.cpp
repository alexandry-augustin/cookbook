#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>

// std::cout base class:   std::ostream

int main()
{
	{
		std::streamsize size;

		size=std::cout.width();
		assert(size==0); //default
		std::cout.width(10);
		assert(std::cout.width()==10);
	}
	{
		char c;

		c=std::cout.fill();
		assert(c==' '); //default
		std::cout.fill('.'); //set fill char
		assert(std::cout.fill()=='.');
	}
	{
		int n_00=0;
		int n_01=1;

		std::cout<<n_00<<" "<<n_01<<std::endl;
		//or
		//std::cout.operator<<(n_00).operator<<(" ").operator<<(n_01);
	}
	{
		char str[16]="test";
		char* p=str;
		std::cout<<p<<std::endl; //test
		std::cout<<*p<<std::endl; //t
	}
	return 0;
}
