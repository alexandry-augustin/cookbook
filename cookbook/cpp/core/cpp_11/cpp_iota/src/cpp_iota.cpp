#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

int main()
{
	std::vector<int> v(25);
	std::iota(v.begin(), v.end(), 65);
	std::for_each(v.begin(), v.end(),
		[](int e) { std::cout<<e<<" "; }
	);
	return 0;
}
