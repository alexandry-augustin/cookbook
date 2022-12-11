#include <assert.h>

int main()
{
	{
		int n=0;
		assert(n++==0);
	}
	{
		int n=0;
		assert(++n==1);
	}
	{
		int i=5;
		int j=0;

		assert((j=++i+1)==7);
	}
	{
		int n=0;
		assert(++n+n==2);
		assert(n==1);
	}
	{
		int n=0;
		assert(n+++n==1);
		assert(n==1);
	}
	{
		int n=0;
		assert(n+++n==1);
		assert(n==1);
	}
	{
		int n=0;
		assert(n+n++==1);
		assert(n==1);
	}
	return 0;
}
