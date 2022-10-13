#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

template <typename T, typename V>
void erase_remove(T& t, V v)
{
	t.erase(std::remove(t.begin(), t.end(), v), t.end());
}

int main()
{
	{
		int a[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::vector<int> v(a, a+10);
	
		assert(v.size()==10);
		erase_remove(v, 5);
		assert(v.size()==9);
	}
	return 0;
}
