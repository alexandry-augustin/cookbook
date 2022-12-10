#ifndef BASE_H
#define BASE_H

#include <string>

struct base
{
	base()
	{
		//Effective c++: item 9
		// 	[...] during base class construction, virtual functions aren't.
		// 	[...] the type of sub is that of the base class. 
		//fct(); //nok: compile-time error
		//init(); //nok: run-time error
	}
	void init() { fct(); }
	virtual std::string fct()=0;
};

#endif
