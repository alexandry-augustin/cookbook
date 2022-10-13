#include <iostream>
#include <cassert>
#include <memory>

class base
{
	int _n;
public:
	base(int n): _n(n) { }
	~base() { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

int main()
{
	{
		std::shared_ptr<base> ptr;
		//ptr=new base(5); //nok
	}
	{
		std::shared_ptr<base> ptr(new base(5));
		//std::shared_ptr<base> ptr=new base(5); //nok: std::shared_ptr constructor is explicit

		assert((*ptr).get()==5);
		assert(ptr->get()==5);
	}
	{
		base b(5);
		std::shared_ptr<base> ptr=std::make_shared<base>(b);

		assert(ptr->get()==5);
	}
	return 0;
}

