#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

// returns bool

bool f_00(int i, int j)
{
	return (i<j);
}

int main ()
{
	{
		int a[]={ 1, 2, 3, 3, 4, 5 };
		std::vector<int> v(a, a+6);

		//std::sort(v.begin(), v.end());

		assert(std::binary_search(v.begin(), v.end(), 3));
		assert(!std::binary_search(v.begin(), v.end(), 6, f_00));
	}
	return 0;
}
