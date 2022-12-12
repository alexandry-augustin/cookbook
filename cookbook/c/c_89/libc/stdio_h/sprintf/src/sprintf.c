#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// A terminating null character is automatically appended after the content.

int main()
{
	{
		char buf[3];
		int ret=sprintf(buf, "%d", 5);
		
		assert(buf[0]=='5');
		assert(buf[1]=='\0');
	}
	return 0;
}
