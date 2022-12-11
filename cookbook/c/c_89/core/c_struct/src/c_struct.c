#include <assert.h>
#include <stdio.h>

struct base_00
{
	int x, y;
};

typedef struct base_01 //name (optional)
{
	int x, y;
} base_01; //alias

typedef struct 
{
	int x, y;
} base_02;

int main()
{
	{
		//base_00 b_00; //nok
		struct base_00 b_00;
		b_00.x=0;
		b_00.y=0;
	}
	{
		base_01 b_00;
		//or
		//struct base_01 b_00;
		b_00.x=0;
		b_00.y=0;
	}
	return 0;
}
