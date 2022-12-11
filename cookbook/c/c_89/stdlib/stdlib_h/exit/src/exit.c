#include <assert.h>
#include <stdlib.h>

// void exit(int status);

int main()
{
	{
		// for portability:
		// EXIT_SUCCESS instead of 0
		// EXIT_FAILURE instead of 1
		assert(EXIT_SUCCESS==0);
		assert(EXIT_FAILURE==1);
	}
	{
		exit(0);
	}
	return 0;
}
