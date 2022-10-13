#include <iostream>
#include <cassert>
#include <cstddef> //NULL std::nullptr_t

int f(int n)
{
	return 0;
}
int f(void* ptr)
{
	return 1;
}

int main()
{
	{
		void* ptr;

		ptr=0;
		assert(f(0)==0);

		ptr=NULL;
		assert(f(0)==0); //if NULL==0, ambiguous otherwise

		ptr=nullptr;
		assert(f(0)==1);
	}
	return 0;
}
