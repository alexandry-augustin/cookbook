#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
	{
		char a[256];
		gets(a);
		assert(strcmp(a, "abc")==0);
	}
	return 0;
}
