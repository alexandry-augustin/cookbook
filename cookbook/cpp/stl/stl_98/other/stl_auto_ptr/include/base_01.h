#ifndef BASE_01_h
#define BASE_01_h

#include <memory>

class base_00;

class base_01
{
	std::auto_ptr<base_00> _ptr;
public:
	std::auto_ptr<base_00>	get_ptr() /*const*/;
	void			set_ptr(std::auto_ptr<base_00> ptr);
};

#endif
