#include <assert.h>
#include <string.h>
#include <stdio.h>

// char* strcpy(char* dest, const char* src);

// same as: while(*dest++ = *src++);

int main()
{
	{
		char a_00[]="abc";

		strcpy(a_00, "012");
		assert(strcmp(a_00, "012")==0);
		printf("%s\n", a_00);
	}
	{
		char a_00[]="abc";
		char a_01[]="012";

		strcpy(a_00, a_01);
		assert(strcmp(a_00, a_01)==0);
	}
	return 0;
}
