#include <time.h> //CLOCKS_PER_SEC, clock_t
#include <stdio.h>
#include <unistd.h> //sleep()

//CPU time rather than elapsed time

// clock(): return CPU time (in ticks) consumed by the program
// CLOCKS_PER_SEC: ticks per sec

void cpu_time()
{
	clock_t t=clock();

	//sleep(1);
	int n=0;
	while(++n<1000000000);

	t=clock()-t;
	printf("%d seconds\n", (int)(t/CLOCKS_PER_SEC));
}

int main(int argc, char* argv[])
{
	cpu_time();
	return 0;
}
