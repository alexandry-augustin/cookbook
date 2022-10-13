#include <iostream>
#include <cassert>

bool check_binary(bool a, bool b, bool c)
{
	return a^b^c && !(a && b && c) || (!a && !b && !c);
}

int main()
{
	assert(check_binary(true, true, true)==false);
	assert(check_binary(true, true, false)==false);
	assert(check_binary(true, false, true)==false);
	assert(check_binary(true, false, false)==true);
	assert(check_binary(false, true, true)==false);
	assert(check_binary(false, true, false)==true);
	assert(check_binary(false, false, true)==true);
	assert(check_binary(false, false, false)==true);

	return 0;
}
