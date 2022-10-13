#include <iterator>
#include <map>
#include <vector>
#include <cassert>
#include <iostream>

int main()
{
	{
		std::vector<int> v(10);

		assert(std::distance(v.begin(), v.end())==10);
		assert(std::distance(v.end(), v.begin())==-10);
	}
	{
		std::vector<int> v(10);
		std::vector<int>::iterator it_00, it_01;

		it_00=v.begin()+5;
		it_01=v.begin()+8;
	
		assert(std::distance(it_00, it_01)==3);
		assert(std::distance(it_01, it_00)==-3);
	}
	{
		std::vector<int> v(10);
		std::vector<int>::iterator it_00;
		std::vector<int>::iterator it_01;

		it_00=v.begin();
		std::advance(it_00, -5);
		assert(std::distance(it_00, v.begin())==5);

		it_01=it_00+5;
		std::advance(it_01, -10);
		assert(std::distance(it_01, it_00)==5);
	}
	{
		typedef std::multimap<int, char> map_t;

		map_t map;
		map.insert(map_t::value_type(0, 'g'));
		map.insert(map_t::value_type(1, 'u'));
		map.insert(map_t::value_type(1, 's'));
		map.insert(map_t::value_type(1, 'g'));
		map.insert(map_t::value_type(4, 'u'));
		map.insert(map_t::value_type(4, 'u'));
		map.insert(map_t::value_type(5, 'u'));

		map_t::iterator it_00=map.begin();
		assert(it_00->second=='g');
		
		std::advance(it_00, 3);
		assert(std::distance(map.begin(), it_00)==3);

		it_00=map.end();
		std::advance(it_00, -4);
		assert(it_00->second=='g');
		//assert(std::distance(map.end(), it_00)==-4); //???

	}
	return 0;
}
