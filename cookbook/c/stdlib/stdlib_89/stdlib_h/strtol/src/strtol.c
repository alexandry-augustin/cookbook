#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// returns 0L on error

int main()
{
	{
		char* str="101";
		long int n=strtol(str, NULL, 2);
		//printf("%d\n", n);
		assert(n==5);
	}
	{
		char* str="111";
		long int n=strtol(str, NULL, 1);
		printf("%d\n", n);
	}
	return 0;
}
