#include <cassert>
#include <iostream>
#include "inc.h"

typedef int int_global_t;

typedef int int_extern_t; //same re-definition is ok
//typedef int_extern_t float; //different re-definition is not-ok

class base
{
public:
	typedef int int_t;

private:
	int_t _n;

public:
	base(int_t n): _n(n) {}

	int_t getN() const { return _n; } 
};

void foo()
{
	typedef int int_local_t;
}

int main(int argc, char* argv[])
{
	{
		int_global_t n=5;
		assert(n==5);
	}
	{
		int_extern_t n=5;
		assert(n==5);
	}
	{
		base::int_t n=6;
		assert(n==6);
	}
	{
		base b(9);
		base::int_t n=b.getN();
		assert(n==9);
	}

	//int_local_t p=0; //NOK

	return 0;
}
