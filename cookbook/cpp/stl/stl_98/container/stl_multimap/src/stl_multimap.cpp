#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{
	{
		typedef std::multimap<std::string, int> map_t;
		//map_t::value_type = std::pair<const key, Type>

		map_t m;
		m.insert(map_t::value_type("a", 1));

		assert(m.size()==1);
	}
	{
		// Compare (<) function not required since it is built into std::string class.
		// else declaration would comparison function in std::multimap definition.
		// i.e. std::multimap<std::string, int, compare> m;

		typedef std::multimap<std::string, int> map_t;

		map_t m;

		m.insert(std::pair<std::string, int>("a", 1));
		m.insert(std::pair<std::string, int>("c", 2));
		m.insert(std::pair<std::string, int>("b", 3));
		m.insert(std::pair<std::string, int>("b", 4));
		m.insert(std::pair<std::string, int>("a", 5));
		m.insert(std::pair<std::string, int>("b", 6));

		assert(m.count("a")==2);
		assert(m.count("b")==3);
		assert(m.count("c")==1);

		for(map_t::iterator it=m.begin(); it!=m.end(); ++it)
			std::cout<<"["<<it->first<<", "<<it->second<<"]"<<std::endl;

		std::pair<map_t::iterator, map_t::iterator> ppp;

		// equal_range(b) returns std::pair<iterator,iterator> representing the range
		// of element with key b
		ppp=m.equal_range("b");

		// Loop through range of maps of key "b"
		std::cout<<std::endl<<"Range of \"b\" elements:"<<std::endl;
		for(map_t::iterator it2 = ppp.first; it2!=ppp.second; ++it2)
			std::cout<<"[" << it2->first<<", "<<it2->second<<"]"<<std::endl;

		// Can't do this (??)
		//   std::cout << ppp.first << std::endl;
		//   std::cout << ppp.second << std::endl;
	
		m.clear();
	}
	{
		typedef std::multimap<int, double> map_t;
	
		map_t m;

		m.insert(std::pair<int, double>(100, 10.0));
		m.insert(std::pair<int, double>(101, 13.0));
		m.insert(std::pair<int, double>(102, 13.0));

		for(map_t::iterator it=m.begin(); it!=m.end(); ++it)
			std::cout<<"["<<it->first<<", "<<it->second<<"]"<<std::endl;

		map_t::iterator it=m.find(100);
		m.erase(it);
	}
	//http://cs.stmarys.ca/~porter/csc/ref/stl/programs/map/multimap03.cpp2html
	return 0;
}
