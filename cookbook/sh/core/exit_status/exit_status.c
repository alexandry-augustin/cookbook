#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	assert(argc==2);
	return atoi(argv[1]);
}
