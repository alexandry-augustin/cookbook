#include <assert.h>
#include <stdio.h>

// (~x) == (-x-1) for every signed integer x

int main()
{
	{
		unsigned char n=1;

		assert(~n==(-n-1));
		assert((unsigned char)~n==254);
	}
	return 0;
}
