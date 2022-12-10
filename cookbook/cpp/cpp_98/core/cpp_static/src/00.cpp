#include "cpp_static.h"

void g()
{
	free_fct(); //ok
	//static_free_fct(); //nok as free_fct is virtual
}
