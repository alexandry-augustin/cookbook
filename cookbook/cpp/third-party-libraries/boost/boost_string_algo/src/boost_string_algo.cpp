#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		std::string str("abc 123 abc 123");
		boost::replace_all(str, "123", "abc");
		assert(str=="abc abc abc abc");
	}
	{
		std::string str1, str2;
		std::vector<std::string> token;
		
		str1="one.two";
		boost::split(token, str1, boost::is_any_of("."));
		str2=boost::algorithm::join(token, "_");
		boost::algorithm::replace_all(str2, "_", ".");
		assert(str1==str2);
	
		token.erase(token.begin());
		assert(boost::algorithm::join(token, ".")=="two");
	}
	//trim
	{
		std::string str1("     1x x x x1     ");
		std::string str2("<>trim<>");
		std::string str3("123abs343");
		assert(boost::trim_left_copy(str1)=="1x x x x1     ");
		boost::trim_right(str1);
		assert(boost::trim_left_copy(str1)=="1x x x x1");
		assert(boost::trim_copy_if(str2, boost::is_any_of("<>"))=="trim");
		assert(boost::trim_copy_if(str3, boost::is_digit())=="abs");
		
		boost::trim_if(str2, boost::is_any_of("<>"));
		assert(str2=="trim");
	}
	{
		std::string str("aBc");
		boost::to_upper(str);
		assert(str=="ABC");
		boost::to_lower(str);
		assert(str=="abc");
	}
	return 0;
}
