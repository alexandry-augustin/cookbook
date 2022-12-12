#include <assert.h>
#include <string.h>

int main()
{
	{
		char a[]="0123456789";
		char b[256];

		memcpy(b, a, strlen(a)+1); //copy a in b
		assert(strcmp(b, "0123456789")==0);
	}
	{
		char a[256];

		memcpy(a, "abc", 3+1);
		assert(strcmp(a, "abc")==0);
	}
	return 0;
}
