#include <assert.h>
#include <string.h> //memset()
#include <stdlib.h>
#include <stdio.h>

// memeset: can only write on allocated memory

struct base_00
{
	int n_00, n_01, n_02;
};

int main()
{
	{
		char a[]="0123456789";
		memset(a, '-', 6);
		assert(strcmp(a, "------6789")==0);
	}
	{
		char a[]="0123456789";
		memset(a+7, '-', 3);
		assert(strcmp(a, "0123456---")==0);
	}
	{
		int n=0;
		int* a=&n;
		//memset(a, 5, sizeof(int)*6); //nok: undefined behavior
	}
	{
		char* a=(char*)malloc(10);
		memset(a, '-', 10);
		//a[9]='\0';
		assert(strcmp(a, "----------")==0);
		memcpy(a, "abc", 3);
		assert(strcmp(a, "abc-------")==0);
	}
	{
		struct base_00 b;
		memset(&b, 1, sizeof(b));
		assert(b.n_00==16843009); //00000001 00000001 00000001 00000001
	}
	return 0;
}
