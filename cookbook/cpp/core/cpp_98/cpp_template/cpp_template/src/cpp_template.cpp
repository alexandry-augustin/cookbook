#include <cassert>
#include <typeinfo>
#include <iostream>

template <typename T>
struct base_02
{
	T t;
};

template <typename T, int TN=0>
class base_00
{
	int _n;
public:
	base_00(): _n(TN) { }
	int& n() { return _n; }
};

//template <int TA, int TB>
//class Add
//{
//public:
//	base_00(): _n(TN) { }
//	int& n() { return _n; }
//};

template <typename T>
struct base_01
{
	const std::type_info& value_type() const { return typeid(T); }
};

template <typename T>
T f_00()
{
	static T t=0;
	return t++;
};

struct base_02
{
	template <typename T0, typename T1, typename Comp>
	bool f_00(T0 t0, T1 t1, Comp comp)
	{
		return Comp(t0, t1);
	}
};

int main()
{
	{
		base_00<int, 5> b0;
		base_00<int> b1;
		
		assert(b0.n()==5);
		assert(b1.n()==0);
	}
	{
		base_01<int> b;
		//assert(b.value_type().name()=='i');
		std::cout<<b.value_type().name()<<std::endl;
	}
	{
		base_02<base_02<int> > b_00;
	}
	{
		assert(f_00<int>()==0);
		assert(f_00<int>()==1);

		assert(f_00<short int>()==0);
		assert(f_00<short int>()==1);
	}
	{
	}
	return 0;
}
