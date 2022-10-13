#include "Base.h"
#include <cassert>
#include <vector>

int main() 
{
	{
		base::Base b(4);
		base::Base* b_ptr=base::base::factory::get(9);
		
		assert(b.n==4);
		assert(b.get()==4);
		assert(b_ptr->n==9);
		assert(b.type==0);
	}
	{
		using namespace std; //valid only in this scope
	}
	return 0;
}
