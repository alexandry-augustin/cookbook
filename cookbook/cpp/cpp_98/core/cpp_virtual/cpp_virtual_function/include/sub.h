#ifndef SUB_H
#define SUB_H

#include "base.h"

struct sub: public base
{
	/*virtual*/ std::string fct() { return "sub"; }
};

#endif
