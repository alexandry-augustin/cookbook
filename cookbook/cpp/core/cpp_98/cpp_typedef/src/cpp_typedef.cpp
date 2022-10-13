#include <cassert>
#include "cpp_typedef.h"
#include "sub.h"
#include "base.h"

struct Base
{
	int n;
	Base(int n_): n(n_) { }
};

class base_00
{
protected:
	typedef int int_t;
};

int main()
{
	{
		//base_00::int_t n; //nok
	}
	{
		Int* n=new Int(8);
		int_ptr m=new Int(9);
		base y(9);
		base_ptr x=new Base(9);
		
		assert(*n==8);
	
		delete n, m;
	}
	{
		sub s;
		//s.n=5; //nok
	}
	return 0;
}
