#include <iostream>
#include <cassert>

void f0(int* ptr)
{
	*ptr=0; //ok
	++ptr; //ok
}

void f1(int* const ptr)
{
	*ptr=0; //ok
//	++ptr; //nok
}

void f2(int const * ptr)
//or
//void f2(const int* ptr)
{
//	*ptr=0; //nok
	++ptr; //ok
}

void f3(int const * const ptr)
//or
//void f3(const int* const ptr)
{
//	*ptr=0; //nok
//	++ptr; //nok
}

void g0(const int n)
{
//	n=0; //nok
}

void g1(int n)
{
	n=0; //ok
}

void h0(int*& ptr)
{
	*ptr=0; //ok
	++ptr; //ok
}

void h1(int* const& ptr)
{
	*ptr=0; //ok
//	++ptr; //nok
}

void h2(int const *& ptr)
//or
//void h2(const int*& ptr)
{
//	*ptr=0; //nok
	++ptr; //ok
}

void h3(int const * const& ptr)
//or
//void h3(const int* const& ptr)
{
//	*ptr=0; //nok
//	++ptr; //nok
}

int main()
{
	int* ptr0=new int(4);
	int* ptr1=ptr0;
	
	f0(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==0);
	
	f1(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==0);
	
	*ptr0=4;
	
	f2(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==4);
	
	f3(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==4);
	
	int n=4;
	
	g0(n);
	assert(n==4);
	
	g1(n);
	assert(n==4);
	
	h0(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==0);
	
	h1(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==0);
	
	*ptr0=4;
	
	h2(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==4);
	
	h3(ptr0);
	assert(ptr0==ptr1);
	assert(*ptr0==4);
	
	return 0;
}
