#include <assert.h>
#include <stdio.h>
#include <string.h>

//fopen() function returns a FILE stream pointer on success while it returns NULL in case of a failure
// (file does not exist, no permission)

// [r]ead
// [w]rite
// [a]ppend

// if a file that does not exist is opened for writting or appending, it is created if possible.
// opening an existing file for writing causes the old content to be discaded, while opening for appending preserves them.

// r	Open for reading. The stream is positioned at the beginning of the file.
// r+	Open for reading and writing. The stream is positioned at the beginning of the file.
// w	Truncate to zero length or create text file for writing. The stream is positioned at the beginning of the file.
// w+	Open for reading and writing. The file is created if it does not exist, otherwise it is truncated. The stream is positioned at the beginning of the file.
// a	Open for appending (writing at end of file). The file is created if it does not exist. The stream is positioned at the end of the file.
// a+	Open for reading and appending (writing at end of file). The file is created if it does not exist. The initial file position for reading is at the beginning of the file, but output is always appended to the end of the file.

int main()
{
	{
		char* path;
		path="unknown";
		FILE* file=fopen(path, "r");
		assert(file==NULL);
	}
	{
		FILE* pFile;
		char* fileName="sample";
		char* text="abc";

		pFile=fopen(fileName, "w");
		if(pFile!=NULL)
		{
			fputs(text, pFile);
			fclose(pFile);
		}

		//reading 
		/*printf("Reading %s", fileName);
		pFile=fopen(fileName, "r");*/

		//copy

		/*FILE *in, *out;
		if((in=fopen(fileName, "rt"))==NULL)
		{
			fprintf(stderr, "Cannot open input file.\n");
			return 1;
		}
		if((out=fopen("output.txt", "wt"))==NULL)
		{
			fprintf(stderr, "Cannot open output file.\n");
			return 1;
		}
		while(!feof(in))
			fputc(fgetc(in), out);
		fclose(in);
		fclose(out);*/
	}
}
