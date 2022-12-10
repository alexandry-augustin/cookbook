#include "Base.h"

//int base::Base::get() const
//{
//	Sub s;
//	Base* b=base::factory::get(9);
//	return n;
//}

// or

namespace base {

int Base::get() const
{
	base0::Base0 b0;
	Sub s;
	Base* b=base::factory::get(9);
	return n;
}

int Sub::get() const
{
	Base y(0);
	return b.n;
}

} //namespace base
