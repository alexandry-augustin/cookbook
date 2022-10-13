#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>

struct is_odd
{
	bool operator()(int i) const
	{
		return (i%2!=0);
	}
};

struct less_than_10
{
	bool operator()(int i) const
	{
		return i<10;
	}
};
;

template <typename FO, typename T>
bool logical_not(T t)
{
	FO fo;
	
	return !fo(t);
}

template <typename FO1, typename FO2, typename T>
bool logical_and(T t)
{
	FO1 fo1;
	FO2 fo2;
	
	return fo1(t) && fo2(t);
}

int main()
{
	assert((logical_and<is_odd, less_than_10, int>(7))==true);
	
	std::vector<int> v;
	for(int i=0; i<20; ++i) v.push_back(i);
	
	assert(std::count_if(v.begin(), v.end(), is_odd())==10);
	assert(std::count_if(v.begin(), v.end(), std::bind2nd(std::less<int>(), 10))==10);
	assert(std::count_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), 10))==9);
	assert(std::count_if(v.begin(), v.end(), logical_and<is_odd, less_than_10, int>)==5);
//	std::cout<<std::count_if(v.begin(), v.end(), logical_and<logical_not<is_odd>, less_than_10, int>)<<std::endl;
//	std::cout<<std::count_if(v.begin(), v.end(), boost::bind(std::logical_and<bool>(), std::bind2nd(std::greater<int>(), 10)))<<std::endl;
	
	return 0;
}
