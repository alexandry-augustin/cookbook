#include <cassert>

class base
{
	int _n;
public:
	base(int n):_n(n) { }
	int& n() { return _n; }
};

int& get()
{
	int n;
	return n; //dangling reference
}

int main()
{
	{
		int a=5;

		int& b=a;
		b=6;
		assert(a==6);

		int* c=&a;
		*c=7;
		assert(a==7);

		c=0;
		c=&b;
		*c=8;
		assert(a==8);
	}
	{
		base b(4);
		int n=b.n();
		n=9;
		assert(n==9);
		assert(b.n()==4);

		b.n()=8;
	}
	{
		//int n=get();
		//Segmentation fault
	}
	return 0;
}
