#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// http://stackoverflow.com/questions/14062910/clearest-way-to-read-and-print-txt-file-lines-in-c

// char* fgets(char * str, int num, FILE * stream);
// reads characters from stream and stores them as a C string into str until (num-1) characters have been read or either a newline or the end-of-file is reached, whichever happens first.
// str[num]='\0' ??

void cat_00(FILE* fp)
{
	int c;
	while((c=getc(fp))!=EOF)
		putchar(c);
}

void cat_01(FILE* fp)
{
	char buffer[2];
	while(fgets(buffer, sizeof(buffer), fp)!=NULL)
		fputs(buffer, stdout);
}

void cat_02(FILE* fp)
{
	char buffer[2];
	int n;
	while((n=fread(buffer, 1, sizeof(buffer), fp))>0)
		fwrite(buffer, 1, n, stdout);
	if(ferror(fp))
	{
		/* deal with error */
	}
}

int main(int argc, char* argv[])
{
	if(argc==1)
		cat_00(stdin);
	
	FILE* fp;
	const char* file;
	while((file=*++argv)!=NULL)
	{
		fp=fopen(file, "r");
		assert(fp!=NULL);
		cat_01(fp);
		fclose(fp);
	}
	exit(EXIT_SUCCESS);
}
