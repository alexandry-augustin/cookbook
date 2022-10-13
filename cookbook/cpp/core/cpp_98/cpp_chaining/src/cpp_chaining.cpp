#include <cassert>

class base
{
	int _n;
public:
	base(int n=0): _n(n) { }
	base& add()
	{
		++_n;
		return (*this);
	}
	int get() const { return _n; }
};

int main(int argc, char* argv[])
{
	{
		base b(0);
		b.add().add();
		assert(b.get()==2);
	}
	{
		base b(0);
		assert(b.add().add().get()==2);
	}
	return 0;
}
