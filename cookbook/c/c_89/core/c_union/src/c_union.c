#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <string.h>
// ~ boost::variant

//disciminated union:
//There is at most one member active, but you can't find out which one.
//You will have to store that information about the currently active member yourself somewhere else.
//Storing such a flag in addition to the union will give you a so called "discriminated union": An union which knows what type in it is currently the "active one".
struct my_variant_t
{
	int type; //type of the active member
	union
	{
		char	char_value;
		short	short_value;
		int	int_value;
		long	long_value;
		float	float_value;
		double	double_value;
		void*	ptr_value;
	};
};

/* construct a new float variant instance */
void init_float(struct my_variant_t* v, float initial_value)
{
	v->type=0;//VAR_FLOAT;
	v->float_value=initial_value;
}

/* Increments the value of the variant by the given int */
void inc_variant_by_int(struct my_variant_t* v, int n)
{
	switch(v->type)
	{
	case 0/*VAR_FLOAT*/:
		v->float_value+=n;
		break;

	case 1/*VAR_INT*/:
		v->int_value+=n;
		break;
	}
}

union base_00_t
{
	unsigned char c[4];
	uint32_t bits;
} base;

union base_01_t
{
	int n;
	char c;
	char str[256];
};

void f_00(union base_01_t b)
{
}

int main()
{
	{
		base.c[0]=1;
		base.c[1]=0;
		base.c[2]=0;
		base.c[3]=0;
		printf("%08x\n", base.bits);
	}
	{
		union base_01_t b;

		assert(sizeof(b)==sizeof(char)*256);

		b.n=5;
		assert(b.n==5);

		b.c='4';
		assert(b.n!=5);

		strcpy(b.str, "abc");
		assert(strcmp(b.str, "abc")==0);
		assert(b.c!='4');
	}
	{
		union base_01_t b;

		f_00(b);
	}
	return 0;
}
