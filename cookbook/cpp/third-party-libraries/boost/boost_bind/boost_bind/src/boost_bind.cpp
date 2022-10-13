#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/ref.hpp>
#include <boost/utility.hpp>
//---------------------------------------------------------
class base_00
{
	int _n;
public:
	base_00(int n=0): _n(n) { }
	int get() const { return _n; }
	void f_00() { ++_n; }
};
//---------------------------------------------------------
struct Base
{
	int n;
	Base(int n): n(n) { }
	int& get() { return n; }
};
//---------------------------------------------------------
struct _base:
       boost::noncopyable
{
	void operator()(int n) { }
};
//---------------------------------------------------------
static int n=0;
//---------------------------------------------------------
void add(int m)
{
	n+=m;	
}
//---------------------------------------------------------
void add_ref(int& n)
{
	++n;
}
//---------------------------------------------------------
int sub(int n)
{
	return --n;	
}
//---------------------------------------------------------
int substract(int a, int b)
{
	return a-b;
}
//---------------------------------------------------------
bool isOdd(Base* b)
{
	return b->n%2!=0;
}
//---------------------------------------------------------
bool less_5(Base* b)
{
	return b->n<5;
}
//---------------------------------------------------------
struct isEven
{
	typedef bool result_type;
	bool operator()(Base* b)
	{
		return b->n%2!=0;
	}
};
//---------------------------------------------------------
struct base_
{
	int n;
	base_(int n_): n(n_) { }
};
//---------------------------------------------------------
struct base
{
	int n;
	void e(int) { }
	void f(int) { }
	void f(double) { }
	void g() const{ }
	void g() { }
	int& h() { return n; }
	const int& h() const{ return n; }
};
//---------------------------------------------------------
struct static_
{
	static int f(int n) { return n; }
};
//---------------------------------------------------------
void f(int) { }
void f(double) { }
//---------------------------------------------------------
//typedef boost::function<void (int)> f_01_t
//void f_01(f_01_t f)
//{
//}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		int n=0;
		boost::bind(add_ref, boost::ref(n))();
		assert(n==1);
	}
	{
		assert(n==0);
		boost::bind(add, 2);
		assert(n==0);
		boost::bind(add, 2)();
		assert(n==2);
	}
	{
		boost::bind(add, 5)();
	}
	{
		_base b;
		_base* c;
		//int n;
		boost::bind(&_base::operator(), boost::ref(b), 5)();
		boost::bind(&_base::operator(), c, 5)();
		boost::bind(&_base::operator(), boost::ref(c), 5)();
		//boost::bind(boost::ref(b), 5)();
	}
	{
		typedef std::map<int, boost::function<void (int)> > map_type;

		map_type map;
		boost::function<int (int)> f;

		f=sub;
		boost::bind(f, boost::bind(&map_type::value_type::second, _1));
		assert(f(7)==6);
	}
	{
		Base b(0);
		boost::bind<int&>(&Base::n, _1)(b)=5;
		assert(b.n==5);
	}
	std::vector<int> v;
	std::vector<Base*> base_v;
	for(int i=0; i<10; ++i)	v.push_back(i);
	for(int i=0; i<10; ++i)	base_v.push_back(new Base(i));
	std::vector<int>::iterator it;
	std::vector<int>::iterator base_it;
	{
		boost::function<int (int)> binded1st=boost::bind(&substract, 2, _1);
		boost::function<int (int)> binded2nd=boost::bind(&substract, _1, 1);
		boost::function<int (int, int)> not_binded=boost::bind(&substract, _1, _2);
		boost::function<int (int, int)> reverse_binded=boost::bind(&substract, _2, _1);
		boost::function<int ()> fully_binded=boost::bind(&substract, 2, 1);

		assert(binded1st(1)==1);
		assert(binded2nd(2)==1);
		assert(not_binded(2, 1)==1);
		assert(reverse_binded(1, 2)==1);
		assert(fully_binded()==1);

		assert(boost::bind(&substract, _1, _2)(2, 1)==1);
	}
	{
		//nested bind
		//check if 0<n<5
		boost::function<bool (int)> f=boost::bind(std::less<int>(), _1, 5);
		boost::function<bool (int)> g=boost::bind(std::greater<int>(), _1, 0);
		//boost::function<bool (int)> h=boost::bind(std::logical_and<bool>(), f(_1), g(_1));
		boost::function<bool (int)> h=
			boost::bind(std::logical_and<bool>(),
			boost::bind(std::less<int>(), _1, 5),
			boost::bind(std::greater<int>(), _1, 0));

		assert(f(2)==true);
		assert(g(2)==true);
		assert(h(2)==true);
		assert(std::count_if(v.begin(), v.end(), h)==4);
	}
	{
//		base_it=std::find_if(base_v.begin(), base_v.end(),
//			boost::bind(std::equal_to<int>(), boost::bind(&Base::get, _1), 1));

//		assert((*base_it)->get()==1);
	}
//	v.erase(std::remove_if(v.begin(), v.end(),
//		boost::bind(std::equal_to<int>(), boost::bind(&Base::get, _1), 0),
//		v.end()));
//	v.erase(std::remove(v.begin(), v.end(), v[6]));
//	std::remove_if(v.begin(), v.end(),
//		boost::bind(std::equal_to<int>(), boost::bind(&Base::get, _1), 1));
		//boost::bind( wrapper, a, boost::bind( c, p ), b ); 
	//wrapper(a, c(p), b)

	//boost::bind( wrapper, a, boost::protect(boost::bind( c, p )), b ); 
	//wrapper(a, boost::bind( c, p ), b)
	{
		std::vector<Base*> v;
		for(int i=0; i<10; ++i)	v.push_back(new Base(i));

		//boost::bind operator overloading
		//! == != < <= > >= && ||

		boost::function<bool (Base*)> f=!boost::bind(isOdd, _1);
		boost::function<bool (Base*)> g=!boost::bind(isEven(), _1);
		boost::function<bool (Base*)> h=boost::bind(isOdd, _1) && boost::bind(less_5, _1);

		assert(std::count_if(v.begin(), v.end(), f)==5);
		assert(std::count_if(v.begin(), v.end(), h)==2);
	}
	{
		assert(boost::bind(&static_::f, 5)()==5);
	}
	{
		//overloaded functions

		//boost::bind(&f, _1); //nok
		//boost::bind(&base::f, _1); //nok

		boost::bind(static_cast<void (*)(int)>(&f), _1);
		boost::bind(static_cast<void (base::*)(int)>(&base::f), _1);
		boost::bind(static_cast<void (base::*)()>(&base::g), _1);
		boost::bind(static_cast<void (base::*)() const>(&base::g), _1);
		boost::bind(static_cast<int& (base::*)()>(&base::h), _1);
		boost::bind(static_cast<const int& (base::*)() const>(&base::h), _1);
	}
	{
//http://stackoverflow.com/questions/2413786/using-for-each-and-boostbind-with-a-vector-of-pointers/2413815#2413815
		std::vector<base_*> v;
		v.push_back(new base_(5));
		//assert(std::find_if(v.begin(), v.end(), boost::bind(&base::n, *_1))!=v.end());
	}
	{
		base b;

		boost::function<void(int)> f=boost::bind(&base::e, b, _1);
	}
	{
		base_00 b;
		boost::function<void()> f=boost::bind(&base_00::f_00, b);

		assert(b.get()==0);
		f();
		assert(b.get()==0);
		f();
		assert(b.get()==0);
	}
	{
		base_00 b;
		boost::function<void()> f=boost::bind(&base_00::f_00, boost::ref(b));

		assert(b.get()==0);
		f();
		assert(b.get()==1);
		f();
		assert(b.get()==2);
	}
	return 0;
}
