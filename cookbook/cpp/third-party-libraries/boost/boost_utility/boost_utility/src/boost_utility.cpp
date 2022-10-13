#include <iostream>
#include <cassert>
#include <cstring>
#include <boost/current_function.hpp>
#include <boost/utility.hpp>
//---------------------------------------------------------
void add(int* n)
{
	++(*n);
}
//---------------------------------------------------------
void foo(int);
//---------------------------------------------------------
int main()
{
	{
		assert(strcmp(BOOST_CURRENT_FUNCTION, "int main()")==0);
	}
	{
		int n=0;
		add(boost::addressof(n));
		assert(n==1);
	}
	{
/*		int value1=BOOST_BINARY(100 111000 01 1 110);
		assert(BOOST_BINARY(10010)
			& BOOST_BINARY(11000)
			== BOOST_BINARY(10000));
		foo(BOOST_BINARY(1010));*/
	}
	return 0;
}
