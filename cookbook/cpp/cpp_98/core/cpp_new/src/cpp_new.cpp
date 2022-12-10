#include <cassert>
#include <iostream>
#include <new>

// new throws std::bad_alloc on faillure
// new(base_ptr) base(); //placement new 

struct base
{
	base(int n=0) { };
	int n;
};

int main()
{
	{
		assert(*new int(25)==25);
	}
	//char memory[sizeof
	{
		int a[5];
		for(int i=0; i<5; ++i)
			a[i]=i;
		for(int i=0; i<5; ++i)
			assert(a[i]==i);
	}
	{
		int* a=new int[5];
		for(int i=0; i<5; ++i)
			a[i]=i;
		for(int i=0; i<5; ++i)
			assert(a[i]==i);
		delete[] a; 
		a=0;
	}
	{
		base* a=new base[5]; // base must have default constructor
		assert(a[0].n==0);
		delete[] a;
	}
	return 0;
}
//new(place) Fred();//cf placement new 
