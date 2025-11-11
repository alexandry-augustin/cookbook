#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
	std::cout<<"[signal:"<<signum<<"]"<<std::endl;
}

int main()
{
	{
		signal(SIGINT, sig_handler);
		sleep(10); // This is your chance to press CTRL-C
	}

	return 0;
}
