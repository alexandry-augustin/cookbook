#include <cassert>
#include <iostream>
#include <vector>

struct base_00
{
	void operator()()
	{
	}
};

int f_00()
{
}

int main()
{
	{
		typedef decltype(f_00()) type_00;
		decltype(f_00()) a[]={ 0, 1, 2, 3 };
		std::vector<decltype(f_00())> v(a, a+4);
	}
	return 0;
}
