#include <cassert>
#include <iostream>

class base_00
{
protected:
	int _n;
public:
	explicit base_00(int n):
		_n(n)
	{
	}
	virtual base_00 operator+(int n) const
	{
		return base_00(_n+n);
	}
	int get_n() const
	{
		return _n;
	}
};

class base_01: public base_00
{
public:
	explicit base_01(int n):
		base_00(n)
	{
	}
	/*virtual*/ base_00 operator+(int n) const
	{
		return base_00(_n+n+1);
	}
};

int main()
{
	{
		base_00* b_00=new base_00(1);
		base_00* b_01=new base_01(1);

		assert((*b_00+1).get_n()==2);
		assert((*b_01+1).get_n()==3);
	}
	return 0;
}
