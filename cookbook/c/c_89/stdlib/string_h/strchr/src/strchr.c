#include <assert.h>
#include <string.h>

int main()
{
	{
		char a[]="0123456789876543210";

		int i=strchr(a, '4')-a;
		assert(i==4);

		assert(strchr(a, 'a')==NULL);
	}
	return 0;
}
