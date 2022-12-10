#include <cassert>

struct base_00
{
	int f_00() const { return 0; }
};

struct base_01: public base_00
{
	int f_00() const { return 1; }
};

struct base_02: public base_01
{
	base_02()
		//: base_00() //error: type ‘base_00’ is not a direct base of ‘base_02’
	{
	}
};

int main()
{
	{
		base_00* b=new base_01;

		assert(b->f_00()==0);
	}
	return 0;
}
