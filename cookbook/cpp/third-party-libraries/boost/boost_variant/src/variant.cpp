#include <boost/variant.hpp>
#include <string>
#include <iostream>

int main()
{
	boost::variant<int, std::string> v;
	v="test";
	std::cout<<v<<std::endl;
	v=45;
	std::cout<<v<<std::endl;
	return 0;
}
