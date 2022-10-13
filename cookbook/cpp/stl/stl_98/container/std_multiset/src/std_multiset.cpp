#include <iostream>
#include <set>
#include <cassert>

int main()
{
	{
		std::multiset<int> set;

		set.insert(5);
		set.insert(5);

		assert(set.size()==2);
	}
	return 0;
}
