#include <cassert>
#include "sub.h"
#include "base.h"

int main()
{
	{
		//Effective c++: item 9
		//constructors/destructors should not call virtual functions
		sub s;
	}
	return 0;
}
