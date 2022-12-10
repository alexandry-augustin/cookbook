#include <cassert>
#include <iostream>
#include <limits>

class base_00
{
	int _n;
public:
	base_00(int n=-1):
		_n(n)
	{
		std::cout<<"[base_00::base_00] ["<<_n<<"]"<<std::endl;
	}
	const int& n() const
	{
		return _n;
	}
};

struct base_01
{
	base_00		b_00, b_01;
	base_00		b_02;

	base_01():
		//ordering the init list is irrelevant
		b_02(2),
		b_01(1),
		b_00(0)
	{
	}

};

struct base_02
{
	base_00		b_00, b_01;

	base_02():
		b_00(b_01.n()), //!! b_01.n() is undefined
		b_01(1)
	{
		assert(b_00.n()!=1);
		assert(b_01.n()==1);
	}

};

int main()
{
	{
		//effective c++ - item 14
		base_01 b_01;
		base_02 b_02;
	}
	return 0;
}
