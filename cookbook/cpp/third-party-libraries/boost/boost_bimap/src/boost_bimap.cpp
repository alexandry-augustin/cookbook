#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>

struct Base
{
	int n;
	int id;
	Base(int id_, int n_): id(id_), n(n_)
	{
	}
	bool operator<(const Base& b) const
	{
		return n<b.n;
	}
};

int main(int argc, char* argv[])
{
	{
		typedef boost::bimap<int, Base>	bimap_type;
		
		bimap_type map;
		Base b0(0, 9);
		Base b1(2, 5);
		Base b2(4, 7);
		Base b3(1, 8);
		Base b4(3, 1);
		Base b5(4, 3);
		Base b6(5, 9);
	
		map.insert(bimap_type::value_type(b0.id, b0));
		map.insert(bimap_type::value_type(b1.id, b1));
		map.insert(bimap_type::value_type(b2.id, b2));
		map.insert(bimap_type::value_type(b3.id, b3));
		map.insert(bimap_type::value_type(b4.id, b4));
		map.insert(bimap_type::value_type(b5.id, b5));  //ignored as duplicate key
		map.insert(bimap_type::value_type(b6.id, b6));  //ignored as duplicate value
		
		assert(!map.empty());
		assert(map.size()==5);
	
		for(bimap_type::left_map::const_iterator it=map.left.begin(); it!=map.left.end(); ++it)
			std::cout<<"[id:"<<it->first<<"][n:"<<it->second.n<<"]"<<std::endl;

		std::cout<<"==="<<std::endl;

		for(bimap_type::right_map::const_iterator it=map.right.begin(); it!=map.right.end(); ++it)
			std::cout<<"[n:"<<it->first.n<<"][id:"<<it->second<<"]"<<std::endl;

//		assert(map.right.at(0)==5);
	}
	{
		typedef boost::bimap<boost::bimaps::multiset_of<int>, boost::bimaps::set_of<int> > bimap_type;
		
		bimap_type bimap;
		bimap.insert(bimap_type::value_type(1, 1));
		bimap.insert(bimap_type::value_type(1, 2));
		bimap_type::left_map& left = bimap.left;
		bimap_type::left_map::iterator it = left.find(1);
		std::cout << "LEFT" << std::endl;
		for(; it != left.end(); ++it)
		{
			std::cout << it->first <<  " " << it->second << std::endl;
		}
		bimap_type::right_map& right = bimap.right;
		bimap_type::right_map::iterator r_it = right.find(2);
		std::cout << "RIGHT" << std::endl;
		for (; r_it != right.end(); ++r_it)
			std::cout << r_it->first << " " << r_it->second << std::endl;
	}
	return 0;
}
