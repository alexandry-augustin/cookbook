#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

//http://stackoverflow.com/questions/11514688/passing-const-pointer-by-reference

void fct_unsafe(const int*& n)
{
}
void fct_safe(int* const& n)
{
}

class Base
{
	std::vector<int> _v;
	int _a[5];
	int* _ptr;
public:
	Base():
		_v(5),
		_ptr(new int(0))
	{
	}
	void set(int i, int n) const
	{
	//	_v[i]=n; //fails
//		_a[i]=n; //fails
	}
	int* get() const
	{
		return _ptr;
	}
	void do_() const
	{
		std::find(_v.begin(), _v.end(), 5);
		std::find_if(_v.begin(), _v.end(), std::bind2nd(std::greater<int>(), 5));
	}
};

class base
{
	int _n;
public:
	const int& n() const { return _n; }
	int& n() { return _n; }
};

int main()
{
	{
		const int n=5;
		int const m=5;

		//n=4; //nok
		//m=6; //nok
	}
	{
		int const * p=new int(5);
		//or
		//const int * p=new int(5);

		//*p=9; //nok
		p++;
	}
	{
		int* const p=new int(5);

		*p=9;
		//p++; //nok
	}
	{
		int const * const p=new int(5);

		//*p=9; //nok
		//p++; //nok
	}
	{
		int a[]={ 0, 1, 2 };
		int const * p=a;

		assert(*p==0);
		//*p=0; //nok
	}
	{
		Base b;
		int* ptr=b.get();
		assert(*ptr==0);
		*ptr=9;
		assert(*ptr==9);
		assert(*b.get()==9);
		b.do_();
	}
	{
		int* n;
		//fct_unsafe(n); //error: not type-safe
		fct_safe(n);
	}
	{
		base b;
		b.n()=5;
		assert(b.n()==5);
	}
	return 0;
}
