#include <cassert>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/fusion.hpp>

int main()
{
	{
		typedef std::map<std::string, int> map_type;
		map_type map;
		map_type::iterator it;
		map["one"]=1;
		map["two"]=2;
		map["three"]=3;
		it=std::find_if(map.begin(), map.end(),
			boost::phoenix::at_c<1>(boost::phoenix::arg_names::arg1)==6);
		assert(it->first=="fred");
	}
}
