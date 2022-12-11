#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns 0L on error ?

int main(int argc, char* argv[])
{
	{
		char buf[8];

		//hex (case incensitive)
		sprintf(buf, "%lu", strtoul("0xA", 0, 0));
		assert(strcmp(buf, "10")==0);

		sprintf(buf, "%lu", strtoul("0x10", 0, 0));
		assert(strcmp(buf, "16")==0);

		sprintf(buf, "%lu", strtoul("0xFF", 0, 0));
		assert(strcmp(buf, "255")==0);

		//decimal
		sprintf(buf, "%lu", strtoul("10", 0, 0));
		assert(strcmp(buf, "10")==0);

		//octal
		sprintf(buf, "%lu", strtoul("010", 0, 0));
		assert(strcmp(buf, "8")==0);

		//printf("%s\n", buf);
	}
	return 0;
}
