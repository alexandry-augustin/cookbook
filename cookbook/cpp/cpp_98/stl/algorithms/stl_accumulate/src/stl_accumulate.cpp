#include <iostream>
#include <cassert>
#include <numeric>
#include <vector>
#include <boost/bind.hpp>

class Base
{
	int _n;
public:
	Base(int n): _n(n) { }
	int& n() { return _n; }
	static Base* accumulate(Base* accumulation_so_far, Base* b)
	{
		return new Base(accumulation_so_far->n()+b->n());
	}
};

struct Add_int
{
	int operator()(int accumulation_so_far, Base* b) const
	{
		return accumulation_so_far+b->n();
	}
};

struct Add_base
{
	Base* operator()(Base* accumulation_so_far, Base* b) const
	{
		return new Base(accumulation_so_far->n()+b->n());
	}
};

int main() 
{
	std::vector<Base*> v;
	for(int i=0; i<10; ++i)
		v.push_back(new Base(i));
	
	int n=std::accumulate(v.begin(), v.end(), int(0), Add_int());
	assert(n==45);
	
	Base* b;
	b=std::accumulate(v.begin(), v.end(), new Base(0), Add_base());
	assert(b->n()==45);
	b=std::accumulate(v.begin(), v.end(),
		new Base(0), boost::bind(&Base::accumulate, _1, _2));
	assert(b->n()==45);
	
	return 0;
}
