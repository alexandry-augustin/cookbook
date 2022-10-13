#include <assert.h>
#include <stdio.h>

int main()
{
	{
		int i=0;
		while(1)
			if(1)
			{
				++i;
				break;
			}

		assert(i==1);
	}
	{
		//if(1)
		//	break; //error: break statement not within loop or switch
	}
	return 0;
}
