#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//int main(void)
//int main(int argc, char* argv[])
int main(int argc, char const * const argv[])
{
	printf("%d %s\n", argc, argv[1]);

	return EXIT_SUCCESS;
}
