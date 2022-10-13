#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// not defined in ANSI-C and is not part of C++, but is supported by some compilers.

// char* itoa(int value, char* str, int base);

int main()
{
	{
		char* str="";
		//str=itoa(999, str, 10);
		printf("%s\n", str);
	}
	return 0;
}
