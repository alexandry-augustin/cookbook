#include <assert.h>
#include <stdbool.h>

int main()
{
	{
		//assert(("oups", 1==1));
	}
	{
#ifdef NDEBUG
#undef NDEBUG
#endif
		assert(false);
#define NDEBUG
	}
	return 0;
}
