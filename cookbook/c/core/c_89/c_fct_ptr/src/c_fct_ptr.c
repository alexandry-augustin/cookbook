#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int f_00() { return 0; }
int f_01() { return 1; }

int main()
{
	{
		//array of function ptrs
		int (*f[])()={ f_00, f_01 };

		int i;
		for(i=0; i<1; ++i)
			assert(f[i]()==i);
	}
	return 0;
}
