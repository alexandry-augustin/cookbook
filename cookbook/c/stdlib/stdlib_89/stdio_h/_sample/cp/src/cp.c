#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cp(FILE* ifp, FILE* ofp)
{
	int c;
	while((c=getc(ifp))!=EOF)
		putc(c, ofp);
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* pFile;
	char* fileName="sample";
	char* text="abc";

	pFile=fopen(fileName, "w");
	if(pFile!=NULL)
	{
		fputs(text, pFile);
		fclose(pFile);
	}

	exit(EXIT_SUCCESS);
}
