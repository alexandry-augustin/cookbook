#include <iostream>
#include <list>
#include <algorithm>
#include <boost/coroutine/all.hpp>
//---------------------------------------------------------
class generator
{
	int lb, ub;
public:
	generator(int lower, int upper): lb(lower), ub(upper) {}
	int operator()() { return lb++; }
	operator bool() const { return lb < ub; }
};
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		generator gen(1,4);
		// invokes the operator bool() 
		while(gen)
			// invokes the operator()() - function object! 
			std::cout << gen() << "\n";
	}
	return 0;
}
