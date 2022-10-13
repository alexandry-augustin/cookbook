#include <cassert>
#include <string>
#include <iostream>
#include <boost/unordered_map.hpp>
//---------------------------------------------------------
int main()
{
	{
		typedef boost::unordered_map<int, std::string> map_t;

		map_t m_00;
		m_00[0]="naught";

		assert(m_00.size()==1);

		m_00[0]="zero";
		assert(m_00.size()==1);
	}
	return 0;
}
