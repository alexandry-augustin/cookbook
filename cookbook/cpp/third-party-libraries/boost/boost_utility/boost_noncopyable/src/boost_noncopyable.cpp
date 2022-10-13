#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
//---------------------------------------------------------
class Base0
	: public boost::noncopyable
{
	int _n;
public:
	Base0(int n=0): _n(n) {}

	int& n() { return _n; }
};
//---------------------------------------------------------
class Base1
{
	Base0 _b;
public:
	Base1(int n=0): _b(n) {}

	Base0& b() { return _b; }
};
//---------------------------------------------------------
class Base2
{
	std::map<std::string, Base0> _b;
public:
	Base0& get(std::string str)
	{
//		return _b[str]; //fails

		Base0 b;
		return b; //dangling ref
	
//		return *_b.find("sfd"); //fails
	}
};
//---------------------------------------------------------
class Base3
{
	std::vector<Base0> _b;
public:
	Base0& get(int i) { return _b[i]; }
};
//---------------------------------------------------------
class Base4
{
	std::map<std::string, boost::shared_ptr<Base0> > _b;
public:
	boost::shared_ptr<Base0> get(std::string str)
	{
		return _b[str];
	}
	void set(std::string str, boost::shared_ptr<Base0> p)
	{
		_b[str]=p;
	}
//	Base0 get(std::string str)
//	{
//		return _b[str].get();
//	}
};
//---------------------------------------------------------
Base0& f0(Base0& b) { return b; }
Base1& f1(Base1& b) { return b; }
int& g0(Base0& b) { return b.n(); }
int& g1(Base1& b) { return b.b().n(); }
//---------------------------------------------------------
int main()
{
	{
		Base0 b0(9);
		Base1 b1(6);
		Base2 b2;
		Base3 b3;
		Base4 b4;

		assert(f0(b0).n()==9);
		assert(f1(b1).b().n()==6);
		assert(g0(b0)==9);
		assert(g1(b1)==6);
		b4.set("test", boost::make_shared<Base0>(b0));
	//	assert(Base4()==6);
	}
	return 0;
}
