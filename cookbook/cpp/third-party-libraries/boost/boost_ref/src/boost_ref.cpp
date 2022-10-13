#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

int add_one(const int& n)
{
	return n+1;
}

void add(int& n)
{
	++n;
}

int main()
{
	{
		int n;
		boost::function<void (int&)> f;
		
		n=0;
		add(n);
		assert(n==1);
		boost::bind(add, n)();
		assert(n==1);
		boost::bind(add, boost::ref(n))();
		assert(n==2);
		assert(boost::bind(add_one, boost::cref(n))()==3);
	}
	
	return 0;
}