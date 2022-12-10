#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator> // for std::ostream_iterator

int main() 
{
	{
		int a[]={10,20,30,40,50,60,70};
		std::vector<int> v(7);

		std::copy(a, a+7, v.begin());

		for(int i=0; i<7; ++i)
			assert(a[i]==v[i]);
	}
	{
		std::vector<int> v(3, 9);

		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout<<std::endl;
	}
	{
		std::vector<int> v(3, 9);
		std::ostringstream oss;

		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(oss, " "));
		assert(oss.str()=="9 9 9 ");
	}

	return 0;
}
