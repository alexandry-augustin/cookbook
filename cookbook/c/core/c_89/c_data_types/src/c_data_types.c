#include <limits.h>
#include <assert.h>
#include <stdio.h>

//used for portability, platform dependent
//size_t: used in sizeof(), malloc(), strlen(), memcpy()
//<stdlib.h>
//void *malloc(size_t n);
//<string.h>
//void *memcpy(void *s1, void const *s2, size_t n);
//size_t strlen(char const *s);

//size_t, time_t, and ptrdiff_t are 64-bit values on 64-bit Windows operating systems.

//the actual size of integer types varies by implementation.
//the standard only requires size relations between the data types and minimum sizes for each data type

// size_t is the unsigned integer type of the result of the sizeof operator (and of the offsetof operator) so it is guaranteed to be big enough to contain the size of the biggest object your system can handle (e.g. a static array of 8Gb).
// It may be bigger, equal or even smaller than an unsigned int and your compiler might make assumption about it for optimization purpose.

//http://stackoverflow.com/questions/2053843/min-and-max-value-of-data-type-in-c
#define umaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
		(0xFULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define smaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
		(0x7ULL << ((sizeof(t) * 8ULL) - 4ULL)))

int main()
{
	{

	}
	{
		const int min_int=INT_MIN;
		const int max_int=INT_MAX;
	}
	{
		assert(5/2==2);
		assert(5.0/2==2.5);
		assert(5/2.0==2.5);
		assert(5.0/2.0==2.5);

	}
	{
		printf("schar: %llx uchar: %llx\n", smaxof(char), umaxof(char));
		printf("sshort: %llx ushort: %llx\n", smaxof(short), umaxof(short));
		printf("sint: %llx uint: %llx\n", smaxof(int), umaxof(int));
		printf("slong: %llx ulong: %llx\n", smaxof(long), umaxof(long));
		printf("slong long: %llx ulong long: %llx\n",
		smaxof(long long), umaxof(long long));
	}

	return 0;
}
