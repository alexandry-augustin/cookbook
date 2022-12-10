#include "base_01.h"
#include "base_00.h"

std::auto_ptr<base_00> base_01::get_ptr() //const
{
	return _ptr;
}

void base_01::set_ptr(std::auto_ptr<base_00> ptr)
{
	_ptr=ptr;
}
