#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

typedef struct 
{
	char ch1;
	short s;
	char ch2;
	long long ll;
	int i;
} base_00;

typedef struct 
{
	long long ll; // @ 0
	int i;        // @ 8
	short s;      // @ 12
	char ch1;     // @ 14
	char ch2;     // @ 15
} base_01;

int main()
{
	{
		size_t sizeof_int=sizeof(int);
		CHAR_BIT; //nb of bits in a byte
		//WORD_BIT;
	}
	{
		//int was originally intended to be the "natural" word size of the processor.
		//the type int should be the integer type that the target processor is most efficient working with.
		//This allows great flexibility: for example, all types can be 64-bit.
		assert(sizeof(long)==sizeof(int));
	}
	{
		//printf("sizeof(bool)=%d\n", sizeof(bool));
		printf("sizeof(char)=%d\n", sizeof(char));
		printf("sizeof(short int)=%d\n", sizeof(short int));
		printf("sizeof(int)=%d\n", sizeof(int));
		printf("sizeof(long int)=%d\n", sizeof(long int));
		printf("sizeof(long long)=%d\n", sizeof(long long int));

		printf("sizeof(uint16_t)=%d\n", sizeof(uint16_t));
		printf("sizeof(int16_t)=%d\n", sizeof(int16_t));

		printf("sizeof(uint32_t)=%d\n", sizeof(uint32_t));
		printf("sizeof(int32_t)=%d\n", sizeof(int32_t));
	}
	{
		//the standard only requires:
		// - size relations between the data types 
		assert(sizeof(char)<=sizeof(short int)<=sizeof(int)<=sizeof(long int)<=sizeof(long long int));
		// - minimum bit counts for each data type
		// NOTE: These size are not specified explicitly in the standard.
		//       They are implied by the minimum/maximum values that MUST be supported
		//       for the type. These limits are defined in limits.h
		assert(CHAR_BIT*sizeof(char)>=8);
		assert(sizeof(char)==1);
		assert(CHAR_BIT*sizeof(short int)>=16);
		assert(CHAR_BIT*sizeof(int)>=16);
		assert(CHAR_BIT*sizeof(long int)>=32);
		assert(CHAR_BIT*sizeof(long long int)>=64);

	}
	{
		printf("sizeof(base_00)=%d\n", sizeof(base_00)); //some padding added for alignment (multiple of the word size)
		printf("sizeof(base_01)=%d\n", sizeof(base_01)); //no padding required
	}
	return 0;
}
