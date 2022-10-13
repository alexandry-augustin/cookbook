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

// no make_unique()

int main()
{
	{
		std::unique_ptr<int> p1(new int);
		std::unique_ptr<int> p2(new int);

	//	p1=new int; //move semantic
	//	p2=p1; //move semantic
		p2=std::move(p1);
		//p2=std::move(new int)
	}
	{
		std::unique_ptr<int> p;

		assert(!p);
		assert(p.get()==0);
		{
			p.reset(new int(5));
		}
		assert(p);
		assert(*p==5);
	}
	return 0;
}

