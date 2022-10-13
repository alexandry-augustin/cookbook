#include <assert.h>
#include <stdio.h>

// modular arithmetic

// 38=14 (mod 12) congruent modulo n
//=> 38%12=14

int main()
{
	{
		int b=2;

		assert(0%b==0);
		assert(1%b==1);
		assert(2%b==0);
		assert(3%b==1);
		assert(4%b==0);
	}
	{
		assert(38/12==3);
		assert(38%12==2);

		assert(12/38==0);
		assert(12%38==12);
	}
	return 0;
}
