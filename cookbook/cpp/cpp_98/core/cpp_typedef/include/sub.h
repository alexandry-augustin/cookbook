#ifndef SUB_H
#define SUB_H

class base_;
//typedef base::int int_type; //nok can't forward declare nested typedef

struct sub
{
	//base::int_type n; //nok
};

#endif
