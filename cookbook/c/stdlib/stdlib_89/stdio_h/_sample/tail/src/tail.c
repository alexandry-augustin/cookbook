#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tail(FILE* f)
{
//	int c;
//	while((c=getc(f))!=EOF)
}

int main(int argc, char* argv[])
{
	if(argc!=1)
	{
		printf("usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* f;
	//argv[1]
	tail(f);

	exit(EXIT_SUCCESS);
}
