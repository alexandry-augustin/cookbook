#include <cassert>
#include <functional>

class base_00
{
	int _n;
public:
	base_00(int n=0): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

int main()
{
	{
		base_00 b;
		std::bind(&base_00::set, &b, std::placeholders::_1);
	}
	return 0;
}
