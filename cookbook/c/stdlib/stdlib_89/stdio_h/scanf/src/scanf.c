#include <assert.h>
#include <stdio.h>

// EOF is when you ask to read some byte(s) and you don't get an error but you get zero bytes read.

// ctrl+d cause EOF (ctrl+z on windows)
// depending on the os, this character will only work if it's the first character on a line,

int main()
{
	char str[255];
	{
//		int n=0;
//		while(n!=EOF)
//		{
//			n=scanf("%s", str);
//			printf("[%d] %s\n", n, str);
//		}
	}
	{
		scanf("%s", str);
		printf("%s\n", str);

		scanf("%s", str);
		printf("%s\n", str);
	}
	return 0;
}
