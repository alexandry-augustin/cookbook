#define MI

#ifdef MI
	#include "multiple_inheritance.h"
#endif
#ifdef DD
	#include "dreaded_diamond.h"
#endif

int main()
{
#ifdef MI
	multiple_inheritance();
#endif
#ifdef DD
	dreaded_diamond();
#endif
	return 0;
}
