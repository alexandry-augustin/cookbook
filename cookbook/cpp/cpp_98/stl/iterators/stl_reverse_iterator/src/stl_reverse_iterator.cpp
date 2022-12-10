#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <algorithm>

struct IsOdd
{
	bool operator()(int n) const
	{
		return (n%2!=0);
	}
};

int main()
{
	typedef std::vector<int>::iterator	fwd_it;
	typedef std::reverse_iterator<fwd_it>	reverse_it;
	
	std::vector<int> v;
	for(int i=0; i<10; ++i) v.push_back(i);

	for(reverse_it it=v.rbegin(); it!=v.rend(); ++it)	
		std::cout<<*it<<" ";
	std::cout<<std::endl;

	{
		fwd_it it=std::find_if(v.begin(), v.end(), IsOdd());
		assert(*it==1);
	}
	{
		reverse_it it=std::find_if(v.rbegin(), v.rend(), IsOdd());
		assert(*it==9);
	}
	return 0;
}
