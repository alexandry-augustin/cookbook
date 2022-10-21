#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int f_00() { return 0; }
int f_01() { return 1; }
int f_02(double m) { return m; }

int main()
{
    {
        // function ptr
        int (*f)(double) = f_02;
        assert(f(4)==4);
    }
	{
		//array of function ptrs
		int (*f[])() = { f_00, f_01 };

		int i;
		for(i=0; i<2; ++i)
			assert(f[i]()==i);
	}

	return 0;
}
