#include <assert.h>
#include <string.h>
#include <stdlib.h>

// size_t strlen()
// returns nb of char between the begining and '\0' ('\0' not included in the count)

int main()
{
	{
		char a_00[]={'a', 'b', 'c', '\0'};
		char a_01[256]={'a', 'b', 'c', '\0'};
		char a_02[256]="abc";	//'\0' automatically appended by compiler
		char a_03[]="abc";	//'\0' automatically appended by compiler
		char a_04[256]={'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};

		assert(strlen(a_00)==3);
		assert(strlen(a_01)==3);
		assert(strlen(a_02)==3);
		assert(strlen(a_03)==3);
		assert(strlen(a_04)==3);
	}
	return 0;
}
