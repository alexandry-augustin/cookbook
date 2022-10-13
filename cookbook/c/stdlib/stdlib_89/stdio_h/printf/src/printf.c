#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// returns: *the total number of characters written ('\0' not included)
// 	    *negative number on failure

// %i or %d	int
// %u		unsigned decimal (integer) number
// %o		octal number (base 8)
// %x or %X	number in hexadecimal (base 16)
//
// %c		char
// %s		string
//
// %f		float
// %e		exponential floating-point number

// \n (newline)
// \t (tab)
// \v (vertical tab)
// \f (new page)
// \b (backspace)
// \r (carriage return)

int main()
{
	{
		printf("%c\n", 'a');
		//assert();
	}
	{
		printf("%06d\n", 1000);
	}
	return 0;
}
