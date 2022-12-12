#include <assert.h>
#include <string.h>

// == strchr in reverse

int main()
{
	{
		char a[]="0123456789876543210";

		int i=strrchr(a, '4')-a;
		assert(i==14);

		assert(strchr(a, 'a')==NULL);
	}
	return 0;
}
