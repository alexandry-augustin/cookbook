#include <assert.h>
#include <stdio.h>

int main()
{
	{
		int n=4;
		int m=3;

		assert((n&m)==0);
	}
	{
		int n=5;
		int m=6;

		assert((n&m)==4);
	}
	return 0;
}
