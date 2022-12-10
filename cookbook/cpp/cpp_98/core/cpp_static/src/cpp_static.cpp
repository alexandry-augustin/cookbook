#include <iostream>
#include <cassert>
#include "cpp_static.h"

// all static members of all the classes are initialized before main() - the order is unpredictable.

/*static*/ int base::m_x=0;

class base_02
{
public:
	int f_00() const
	{
		static int n=5; //common to all instances
		return ++n;
	}
};

static int n; //reachable only in this cpp file

void free_fct()
{
}

static void static_free_fct()
{
}

int main()
{
	{
		for(int i=0; i<2; ++i)
			assert(base_00::fct()==0);
	}
	{
		global=5;
		assert(global==5);
	}
	{
		/*base b, c;
		b.set(7);
		std::cout<<c.get()<<std::endl;
		std::cout<<base::get()<<std::endl;*/
	}
	{
		base_02 b_00;
		base_02 b_01;

		assert(b_00.f_00()==6);
		assert(b_00.f_00()==7);
		assert(b_01.f_00()==8);
		assert(b_01.f_00()==9);
	}
	return 0;
}
