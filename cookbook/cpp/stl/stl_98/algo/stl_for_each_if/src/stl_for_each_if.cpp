#include <iostream>
#include <string>
#include <vector>
#include <cassert>

struct Base
{
	Base(int m): n(m) {}
	int n;
};

template< typename InputIterator, typename OutputIterator, typename Predicate, typename Function>
void for_each_if(InputIterator begin, InputIterator end, Predicate pred, Function fn)
{
	while(begin!=end)
	{
		if(pred(*begin))
			fn(*begin);
		++begin;
	}
};

bool isOdd(Base* b)
{
	return (b->n%2!=0);
}

void do_(Base* b)
{
	std::cout<<b->n<<" ";
}

int main()
{
	{
		std::vector<Base*> v;
		for(int i=0; i<10; ++i) v.push_back(new Base(i));
		
		for_each_if(v.begin(), v.end(), isOdd, do_);
	}
	
	return 0;
}
