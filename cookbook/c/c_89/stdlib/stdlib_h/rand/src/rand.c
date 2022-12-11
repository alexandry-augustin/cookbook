#include <assert.h>
#include <stdio.h>
#include <stdlib.h>	//rand() srand()
#include <time.h>	//time()

int main() 
{ 
	srand(1); //seed (default =1) (unsigned int)
	srand((unsigned)time(0));

	{
		int n=-1;

		n=rand(); //range 0 to RAND_MAX

		assert(RAND_MAX==2147483647);
		assert(n>=0);
		assert(n<=RAND_MAX);
	}
	{
		int n=rand();

		assert(n%10<10);
		assert(n%10>=0);

		assert(n%10+5<15);
		assert(n%10+5>=5);
	}
	{
		int lowest=1, highest=3;
		int range=(highest-lowest)+1; 
		int i;
		for(i=0; i<10; i++)
		{
			
			printf("%d\n", rand());
			int n=lowest+(int)(range*rand()/(RAND_MAX + 1.0));  //WRONG
			printf("%d\n", n);
		}
	}
	return 0;
}
