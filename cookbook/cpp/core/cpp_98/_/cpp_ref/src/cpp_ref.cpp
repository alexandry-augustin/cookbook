#include <cassert>

class base_00 {};
class base_01: public base_00 {};
class base_02: public base_01 {};

struct A
{
	int f(const base_00&)
	{
		return 0;
	}
	int f(const base_01&)
	{
		return 1;
	}
};

int main()
{
	A a;
	{
		base_00 b_00;
		assert(a.f(b_00)==0);

		base_01 b_01;
		assert(a.f(b_01)==1);
	}
	{
		base_01 b_01;
		base_00& b_00=b_01;

		assert(a.f(b_00)==0);
		assert(a.f(static_cast<base_01&>(b_00))==1);
	}
	return 0;
}
