#include <iostream>
#include <time.h>

int main()
{
	{
		int milisec = 100; // length of time to sleep, in miliseconds
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = milisec * 1000000L;
		nanosleep(&req, (struct timespec *)NULL);
	}

	return 0;
}
