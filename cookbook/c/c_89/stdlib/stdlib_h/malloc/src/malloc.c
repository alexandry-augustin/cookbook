#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	{
		int* a=(int*)malloc(10*sizeof(a));
		int i;
		for(i=0; i<10 ;++i)
			a[i]=i;
		for(i=0; i<10 ;++i)
			assert(a[i]==i);
	}
	{
		int* ptr=(int*)malloc(sizeof(int));
		if(ptr==NULL)
		{
			//assert(false);
			return 1;
		}
		*ptr=5;
		assert(*ptr==5);

		free(ptr);
	}
	return 0;
}
