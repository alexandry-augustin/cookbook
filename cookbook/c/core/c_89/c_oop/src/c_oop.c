#include <assert.h>
#include <stdio.h>

typedef struct
{
	int _n;
	int (*f)(int);
	void (*init)(int n);
} base_00;

void base_00_init(int n)
{
}

int base_00_f(int n)
{
	return n;
}

int main()
{
	{
		base_00 b_00;

		b_00.init=base_00_init;
		b_00.f=base_00_f;

		b_00.init(9);

		assert(b_00.f(5)==5);
	}
	return 0;
}
