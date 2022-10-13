#include <iostream>
#include <string>
#include <cassert>
#include <boost/format.hpp>

int main()
{
	{
		std::cout<<(boost::format("%|4t|%1%")%"test")<<std::endl;
	}
	{
		boost::format f("_%1%_%2%_");
		f%"one";
		f%"two";
		std::string str(f.str());
		assert(str=="_one_two_");
	}
	{
		std::string str("_%1%_%2%_");
		boost::format f(str.c_str());
		f%"one";
		f%"two";
		boost::format f0(f.str());
	}
	
	return 0;
}
