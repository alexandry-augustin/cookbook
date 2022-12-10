#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>

class greater_than:
	public std::unary_function<int, bool>
{
	int _n;
public:
	greater_than(int n)
		:_n(n)
	{
	}

	result_type operator()(argument_type arg)
	{
		return (result_type)(arg>_n);
	}
};

class Base
{
	int	_n;

public:
	Base(int n):
		_n(n)
	{
	}

	int& n()
	{
		return _n;
	}
};

struct IsOdd:
	public std::unary_function<Base, bool>
{
	bool operator()(Base b) const
	{
		return (b.n()%2!=0);
	}
};

bool isEven(int n)
{
	return (n%2==0);
}

int main()
{
	typedef typename std::unary_function<int, bool>		unary_fct;
	typedef typename std::binary_function<int, int, bool>	binary_fct;
	{
		std::less<int> b;
		std::binary_negate<std::less<int> > not_g(b);
		std::binder1st<std::less<int> > g_bind1st=std::bind1st(b, 1);
		//unary_fct g_bind1st=std::bind1st(b, 1);
		std::binder2nd<std::less<int> > g_bind2nd=std::bind2nd(b, 2);
		//unary_fct g_bind2nd=std::bind2nd(b, 2);
		
//		std::binder2nd<std::binder1st<std::less<int> > > g_binded=std::bind2nd(std::bind1st(b, 1), 2);
		//assert(std::bind1st(std::bind1st(b, 1), 2)()==true);
		//std::bind1st(std::bind1st(b, 1), 2);
		
		assert(b(1, 2)==true);
		
		assert(g_bind1st(2)==true);
		assert(g_bind2nd(1)==true);
		
		assert(std::bind1st(b, 1)(2)==true);
		assert(std::bind2nd(b, 2)(1)==true);
		
		assert(not_g(1, 2)==false);
		
		assert(std::not2(b)(1, 2)==false);

//	assert(std::bind1st(std::bind1st(std::less<int>(), 2), 5)()==false);
	}
	{
		std::logical_and<bool> and_;
		std::less<int> l;
		std::greater<int> g;
		std::vector<int> v;
		for(int i=0; i<10; ++i) v.push_back(i);
		
		assert(l(1, 2)==true);
		assert(g(1, 0)==true);
		assert(isEven(2)==true);
		assert(and_(l(1, 2), g(1, 0))==true);
		assert(and_(isEven(2), and_(l(1, 2), g(1, 0)))==true);
		
		int n=2;
		//check if 0<n<5
		assert(std::logical_and<bool>()(std::less<int>()(n, 5), std::greater<int>()(n, 0))==true);
		
		assert(std::count_if(v.begin(), v.end(), std::bind2nd(g, 2))==7);
		assert(std::count_if(v.begin(), v.end(), std::bind2nd(l, 5))==5);
	}
	{
		int a[]={ 0, 5, 10, 15, 20, 25 };
		std::vector<int> v(a, a+6);
		std::vector<int>::iterator::difference_type n;
		
		//n>10
		n=std::count_if(v.begin(), v.end(), std::bind1st(std::less<int>(), 10));
		assert(n==3);
		
		//n<10
		n=std::count_if(v.begin(), v.end(), std::bind2nd(std::less<int>(), 10));
		assert(n==2);
		
		//n>5
		n=std::count_if(v.begin(), v.end(), greater_than(5));
		assert(n==4);
		
		Base b(9);
		
		IsOdd isOdd;
		assert(isOdd(b));
		//assert(std::bind1st(IsOdd(), b));
		//assert(std::bind1st(IsOdd(), b));
	}
	return 0;
}
