#include <iostream>
#include <cassert>

//In C++, a union can have member functions, including constructors and destructors, but not virtual member functions.
//A union cannot be used as a base class and cannot be derived from a base class.
//A C++ union member cannot be a class object that has a constructor , destructor, or overloaded copy assignment operator. In C++, a member of a union cannot be declared with the keyword static.

union base_00
{
private:
	int _m;
public: //default
	int _n;
	char _str[256];	

	base_00(int n):	_n(n) { }
	~base_00() { }
	void f_00()
	{
		char str[512];
	}
};

int main()
{
	{
		base_00 b(5);
		assert(b._n==5);
		assert(sizeof(base_00)==256);

		b.f_00();
	}
	return 0;
}
