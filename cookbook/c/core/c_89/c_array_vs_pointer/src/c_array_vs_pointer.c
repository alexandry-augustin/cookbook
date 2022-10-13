#include <assert.h>
#include <stdio.h>

// Arrays automatically allocate space, but can't be relocated or resized.
// Pointers must be explicitly assigned to point to allocated space, but can be reassigned at will

int main()
{
	{
		int a[]={0, 1, 2};
		int* p=a;

		p++;
		assert(a[1]==1);
		assert(p[1]==2);
	}
	{
	}
	return 0;
}
