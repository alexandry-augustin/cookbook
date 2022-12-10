#include <iostream>
#include <cassert>

int main()
{
	{
		int a[]={0, 1, 2, 3};

		for(int n: a)
			assert(n==*a++);

		for(int& n: a)
			n+=1;
	}
	return 0;
}
