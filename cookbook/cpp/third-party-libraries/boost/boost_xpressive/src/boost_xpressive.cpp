#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

int main()
{
	{
		std::string hello("hello world!");
		boost::xpressive::sregex rex=boost::xpressive::sregex::compile("(\\w+) (\\w+)!");
		boost::xpressive::smatch what;
		if(boost::xpressive::regex_match(hello, what, rex))
		{
			std::cout<<what[0]<<std::endl; // whole match
			std::cout<<what[1]<<std::endl; // first capture
			std::cout<<what[2]<<std::endl; // second capture
		}
	}
	
	return 0;
}