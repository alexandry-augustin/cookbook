#include <string>
#include <iostream>
#include <boost/regex.hpp>
//#include <gimo/BaseRegex.h>
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		//BaseRegex regex("test|hi");
		//std::cout<<regex.match(argv[1])<<std::endl;
	}
	{
		std::string str("<data><player><name>Test</name><id>987</id></player></data>");
		boost::regex regex("<data><player><name>[a-zA-Z]*</name><id>[0-9]*</id></player></data>");
		assert(boost::regex_match(str, regex));
	}
	{
		std::string str("abc.def");
		boost::regex regex(".*\\.def");
		assert(boost::regex_match(str, regex));
	}
	{
		std::string str("abc.def");
		boost::regex regex(".*");
		assert(boost::regex_match(str, regex));
	}
	{
		std::string str("20140801.2359.txt");
		boost::regex regex("^(19|20)[0-9][0-9][0-1][0-9][0-3][0-9]\\.[0-2][0-9][0-5][0-9]\\.txt");
		assert(boost::regex_match(str, regex));
	}
	{
		std::string str("20140801.0002.abc.txt");
		boost::regex regex("^(19|20)[0-9][0-9][0-1][0-9][0-3][0-9]\\.[0-2][0-9][0-5][0-9].*\\.txt");
		assert(boost::regex_match(str, regex));
	}
}
