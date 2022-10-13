#include <iostream>
#include <cassert>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
//---------------------------------------------------------
//http://stackoverflow.com/questions/12446596/c-boost-bind-performance
//boost::bind and std::bind will copy their arguments so that the returned object contains a copy of each argument, including the function object. If those arguments are expensive to copy then it will be expensive to pass them to std::bind.
//---------------------------------------------------------
class base_00
{
	int a[1000];
};
//---------------------------------------------------------
void f_00(int n)
{
}
//---------------------------------------------------------
void f_01(base_00 b)
{
}
//---------------------------------------------------------
void f_02(const base_00& b)
{
}
//---------------------------------------------------------
int main()
{
	base_00 b;
	boost::function<void()> f=boost::bind(f_01, b);

	int n;
	while(n++<1000000)
	{
		boost::bind(f_00, 5)();
			//real	0m0.077s
			//user	0m0.072s
			//sys	0m0.004s

		//boost::bind(f_01, b)();
			//real	0m2.925s
			//user	0m2.916s
			//sys	0m0.004s

		//boost::bind(f_01, boost::ref(b))();
			//real	0m0.605s
			//user	0m0.600s
			//sys	0m0.000s

		//boost::bind(f_02, b)();
			//real	0m2.621s
			//user	0m2.608s
			//sys	0m0.000s
		//f();
			//real	0m0.559s
			//user	0m0.548s
			//sys	0m0.000s
	}

	return 0;
}
