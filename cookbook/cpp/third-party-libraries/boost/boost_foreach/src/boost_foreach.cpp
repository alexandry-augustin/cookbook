#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <map>
#include <boost/foreach.hpp>
//---------------------------------------------------------
//#define foreach         BOOST_FOREACH
//#define reverse_foreach BOOST_REVERSE_FOREACH
//---------------------------------------------------------
struct Base
{
	Base(int m): n(m) {}
	int n;
};
//---------------------------------------------------------
int main()
{
	{
		std::string str("Hello, world!");
		BOOST_FOREACH(char c, str)
			std::cout<<c;
		std::cout<<std::endl;
	}
	{
		int a[]={ 1, 2, 3 };
		BOOST_FOREACH(int i, a)
		{
			std::cout<<"["<<i<<"]";
			//if(i==0) return;
			//if(i==1) continue;
			//if(i==2) break;
		}
		std::cout<<std::endl;
	}
	{
		std::vector<int> v(4);
		BOOST_FOREACH(int i, v)
			v[i]=i;
		BOOST_FOREACH(int i, v)
			std::cout<<"["<<v[i]<<"]";
		std::cout<<std::endl;
	}
	{
		std::vector<Base*> v;
		for(int i=0; i<10; ++i) v.push_back(new Base(i));
	
		BOOST_FOREACH(Base* b, v)
		{
			assert(b->n<10);
		}
	}
	{
		typedef std::map<int, std::string>	map_type;

		map_type map;
		map[0]="ZERO";
		map[1]="ONE";
		
		BOOST_FOREACH(map_type::value_type pair, map)
		//BOOST_FOREACH(const map_type::value_type& pair, map)
		{
			pair.first;
			pair.second;
		}
	}
	return 0;
}
