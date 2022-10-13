#include <assert.h>
#include <stdio.h>
#include <math.h>

int main()
{
	{
		unsigned int n=1; //0x01

		n=n<<1;
		//or
		//n<<=1;

		assert(n==2); //0x02
	}
	{
		unsigned int n=2;

		n=n>>1;
		//or
		//n>>=1;

		assert(n==1);
	}
	{
		unsigned int n=0;
		unsigned int m=0;
		unsigned char s=0;

		m=n<<s;
		assert(m==s*pow(2, s));
	}
	return 0;
}
