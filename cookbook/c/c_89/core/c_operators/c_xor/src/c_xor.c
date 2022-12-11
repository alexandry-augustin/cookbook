#include <assert.h>
#include <stdio.h>

// use for:
// * parity check (checksum)
// * xor swap
// * int parity

int main()
{
	{
		//truth table
		assert(0^0==0);
		assert(0^1==1);
		assert(1^0==1);
		assert(1^1==0);
	}
	{
		//properties
		srand((unsigned)time(0));
		int n=rand();
		int m=rand();
		int o=rand();

		assert(n^0==n);
		assert(n^1==~n);
		assert(n^n==0);
		assert(n^m==m^n); //commutativity
		assert((n^m)^o==n^(m^o)); //associativity
		assert(n^m==((~n&m)|(n&~m))); //definition

		assert(0^1^0==1); //if number 1 odd => true
		assert(1^1^0==0); //if number 1 even => false
	}
	{
		//xor swap
		int n=2, m=3;
		
		n=n^m;
		m=n^m; //=(n^m)^m=n^(m^m)=n^0=n
		n=n^m; //=(n^m)^(n)=n^(m^n)=n^(n^m)=(n^n)^m=0^m=m
		//or
		//m=n^m;
		//n=n^m;
		//m=n^m;

		assert(n==3);
		assert(m==2);
	}
	return 0;
}
