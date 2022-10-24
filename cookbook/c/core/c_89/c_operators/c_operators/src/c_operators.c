#include <assert.h>
#include <stdio.h>

void f(int n, int m, int* _n, int* _m)
{
	*_n=n;
	*_m=m;
}

void test_comma_operator()
{
	{
		int a[]={0, 1, 2, 3, 4};
		int i=0;
		int n=0;

		n=(i++, a[i]);
		assert(n==1);
		
		n=(i++, i++, a[i]);
		assert(n==3);
	}
	{
		//if(failure)
		//	return (errno=EINVAL, -1);
	}
	{
		int i=10, b=20, c=30;

		i=b, c;
		assert(i==20);

		i=(b, c);
		assert(i==30);
	}
}

void ternary_operator()
{
    int i = 5;
    int j = 10;
    int min = (i < j) ? i : j;
    assert(min==i);
}

int main()
{
	{
		int n=0, m=0, i=1;

		f(i, i++, &n, &m);

		assert(i==2);
		assert(n==2);
		assert(m==1);
	}
	{
		int n=0, m=0, i=1;

		f(i++, i, &n, &m);

//		printf("%d %d\n", p, q);
		assert(i==2);
		assert(n==1);
		assert(m==2);
	}
	test_comma_operator();
    ternary_operator();

	return 0;
}
//Sequence Points
