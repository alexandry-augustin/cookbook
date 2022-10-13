#include "Base.h"

Base::Base(int n):
	_n(n)
{
}

int& Base::n()
{
	return _n;
}