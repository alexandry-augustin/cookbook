#include <cassert>

// curiously recurring template pattern

template <typename T>
class Base
{
	int _n;
public:
	Base():
		_n(0)
	{
	}
	int& n() { return _n; }
};

int main()
{
	return 0;
}
