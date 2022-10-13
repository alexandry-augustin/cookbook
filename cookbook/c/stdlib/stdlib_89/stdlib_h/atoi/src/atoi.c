#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// int atoi(const char* str)

int main()
{
	{
		char a[]="123";
		int n=atoi(a);
		assert(n==123);
	}
	{
		char a[]={' ', '+', '1', '2', '3', ' ', '\0', '4', '5', '6'};
		int n=atoi(a);
		assert(n==123);
	}
	return 0;
}
