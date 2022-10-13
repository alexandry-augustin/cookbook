#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/shared_ptr.hpp>

namespace std {
template< typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator copy_if(InputIterator begin, InputIterator end, OutputIterator dest_begin, Predicate pred)
{
	while(begin!=end)
	{
		if(pred(*begin))
			*dest_begin++=*begin;
		++begin;
	}
	return dest_begin;
}
} //namespace std

struct Base
{
	Base(int n): n(n) { }
	int n;
	int getN() const { return n; }
};

int square(int x) { return x*x; }

bool isOdd(Base* b) { return b->n%2!=0; }

struct isEven
{
	typedef bool result_type;
	bool operator()(Base* b) { return b->n%2!=0; }
};

struct nitesh
{
	int* f(int n)
	{
		return new int(n);
	}
};

struct base_
{
	virtual int get_n() const=0;
	virtual int* get_ptr_n() const=0;
};

struct sub_: public base_
{
	/*virtual*/ int get_n() const { return 5; }
	/*virtual*/ int* get_ptr_n() const { return new int(5); }
	/*virtual*/ int* is(int m) const
	{
		int* n=new int(5);
		if(m==*n)
			return n;
		else
			return new int(-1);
	}
};

struct base
{
	int* _n;
public:
	base(int n=0): _n(new int(n)) {}
	int* get_n() const { return _n; }
	void set_n(int* n) { _n=n; }
	void str() const { std::cout<<(*_n)<<std::endl; }
};

struct sub
{
	int m;
	int get_m() const { return m; }
	sub(int n=0): m(n) { }
};

class boolean
{
	bool _b;
public:
	boolean(bool b=true): _b(b) { }
	bool is_true() const { return _b; }
	void is_true(bool b) { _b=b; }
};

struct test
{
	int n;
	void f(int) { }
	void f(double) { }
	void g() const{ }
	void g() { }
	int& h() { return n; }
	const int& h() const{ return n;}
};

void f(int) { }
void f(double) { }

bool g(int* n, int m) { return *n==m; }

struct BASE
{
    typedef boost::shared_ptr<BASE> Ptr;
    virtual int it() const = 0;
};

struct SUB: public BASE
{
    typedef boost::shared_ptr<SUB> Ptr;
    virtual int it() const { return 3; }
};

int main(int argc, char* argv[])
{
	{
		std::list<int> l(10);
	
		std::for_each(l.begin(), l.end(), boost::lambda::_1=1);
	
		boost::function<void (int)> f=boost::lambda::_1=1;
		std::for_each(l.begin(), l.end(), f);
	
		for(std::list<int>::const_iterator it=l.begin(); it!=l.end(); ++it)
			assert(*it==1);
	}
	{
		typedef typename std::map<std::string, int> map_type;
	
		map_type m;
		m["one"]=1;
		m["two"]=2;
		m["three"]=3;
	
		std::for_each(m.begin(), m.end(),
			std::cout<<boost::lambda::constant("[")<<boost::lambda::bind(&map_type::value_type::first, boost::lambda::_1)
			<<", "<<boost::lambda::bind(&map_type::value_type::second, boost::lambda::_1)<<"]\n"
			);
	}
	{
		boost::function<int (int)> f=boost::lambda::bind(square, boost::lambda::_1);
		assert(f(5)==25);
	}
	{
		boost::lambda::constant(true);
	}
	{
		boost::function<void (int, int, int)> f;
	
		(std::cout<<boost::lambda::_1<<" "<<boost::lambda::_2<<" "<<boost::lambda::_3<<"\n")("1", "2", "3");
	
		f=std::cout<<boost::lambda::_1<<"*"<<boost::lambda::_2<<"+"<<boost::lambda::_3<<"="<<
			boost::lambda::_1*boost::lambda::_2+boost::lambda::_3<<"\n";
		f(1, 2, 3);
	}
	{
		boost::function<int (int, int)> add=boost::lambda::_1+boost::lambda::_2;
	
		assert((boost::lambda::_1+boost::lambda::_2)(1, 1)==2);
		assert(add(1, 1)==2);
	}
	{
		std::vector<int> v(10);
		for(int i=0; i<10; ++i) v.at(i)=i;
	
		assert(std::count_if(v.begin(), v.end(), boost::lambda::_1>0)==9);
		assert(std::count_if(v.begin(), v.end(), boost::lambda::_1==0)==1);
		assert(std::count_if(v.begin(), v.end(), boost::lambda::_1%2==0)==5);
		assert(std::count_if(v.begin(), v.end(), boost::lambda::_1==0 || boost::lambda::_1==5)==2);
		assert(std::count_if(v.begin(), v.end(), boost::lambda::bind(square, boost::lambda::_1)==4)==1);
	}
	{
		std::vector<Base*> v(10), w;
		for(int i=0; i<10; ++i) v.at(i)=new Base(i);
		boost::function<bool (Base*)> f;
	
		//_1 does not return Base*, it returns a functor with operator*() defined which creates a functor where operator()() takes
		//an argument and dereferences it for its return value. Therefore:
		//assert(std::count_if(v.begin(), v.end(), (boost::lambda::_1)->n==5)==1); //impossible
		assert(std::count_if(v.begin(), v.end(), boost::lambda::bind(&Base::getN, *boost::lambda::_1)==5)==1);
	
		f=boost::lambda::bind(&Base::getN, *boost::lambda::_1)==5
			|| boost::lambda::bind(&Base::getN, *boost::lambda::_1)==0;
		assert(std::count_if(v.begin(), v.end(), f)==2);
		//or
//		assert(std::count_if(v.begin(), v.end(), 
//			boost::lambda::bind(&Base::getN, *boost::lambda::_1)==5
//			|| boost::lambda::bind(&Base::getN, *boost::lambda::_1)==0
//			)==2);
	
		f=isEven();
		assert(std::count_if(v.begin(), v.end(), boost::lambda::bind(f, boost::lambda::_1)==true)==5);
//		assert(std::count_if(v.begin(), v.end(), boost::lambda::bind(isEven(), boost::lambda::_1)==true)==5);

		assert(std::count_if(v.begin(), v.end(), boost::lambda::bind(isOdd, boost::lambda::_1)==true)==5);
	
		std::copy_if(v.begin(), v.end(), back_inserter(w), boost::lambda::bind(&Base::getN, *boost::lambda::_1)==5);
		assert(w.size()==1);
	}
	{
		Base b(0);
		boost::lambda::bind(&Base::n, boost::lambda::_1)(b)=5;
		assert(b.n==5);

		boost::mem_fn(&Base::n)(b)=5;
	}
	{
		int i=0;
		boost::lambda::var(i)++;
		assert(i==0);
	}
	{
		sub* b=new sub(6);
		int n=(b->* &sub::m); //ref on m
		assert(n==6);
		n=7;
		//assert(b->m==7);
	}
	{
		std::set<base*> set;
		set.insert(new base(0));
		set.insert(new base(1));
		set.insert(new base(2));
		std::for_each(set.begin(), set.end(),
			//base->str()
			boost::lambda::bind(&base::str, *boost::lambda::_1)
			);
	}
	{
		typedef typename std::map<std::string, base*> map_type;
		map_type map;
		map_type::const_iterator it;
		
		map["zero"]=new base(0);
		map["one"]=new base(1);
		map["two"]=new base(2);
		
		std::for_each(map.begin(), map.end(), 
			//(*pair.second)->str()
			boost::lambda::bind(&base::str,
				*boost::lambda::bind(&map_type::value_type::second, boost::lambda::_1))
			);
		
		std::for_each(map.begin(), map.end(),
			std::cout
			<<boost::lambda::constant("[")
			<<boost::lambda::bind(&map_type::value_type::first, boost::lambda::_1)
			<<", [n:"
			//*(*pair.second)->get_n()
			<<*boost::lambda::bind(&base::get_n,
				*boost::lambda::bind(&map_type::value_type::second, boost::lambda::_1))
			<<"]]\n"
			);
		
		it=std::find_if(map.begin(), map.end(),
			//*(*pair.second)->get_n()==2
			*boost::lambda::bind(&base::get_n,
				*boost::lambda::bind(&map_type::value_type::second, boost::lambda::_1))==2
		    );
		assert(it!=map.end());
		assert(it->first=="two");
		
		it=std::find_if(map.begin(), map.end(),
			boost::lambda::bind(&map_type::value_type::first, boost::lambda::_1)=="two"
		    );
		assert(it!=map.end());
		assert(it->first=="two");
		
		it=std::find_if(map.begin(), map.end(),
			boost::lambda::bind(&map_type::value_type::first, boost::lambda::_1)=="two"
			//*(*pair.second)->get_n()==2
			&& *boost::lambda::bind(&base::get_n,
				*boost::lambda::bind(&map_type::value_type::second, boost::lambda::_1))==2
		    );
		assert(it!=map.end());
		assert(it->first=="two");
	}
	{
		std::vector<sub*> v;
		v.push_back(new sub(0));
		v.push_back(new sub(1));
		v.push_back(new sub(2));
		std::vector<sub*>::iterator it=
			find_if(v.begin(), v.end(), 
					//boost::lambda::bind(&sub::m, boost::lambda::_1)==2
					boost::lambda::bind(&sub::get_m, boost::lambda::_1)==2
				);
		assert(it!=v.end());
		assert((*it)->m==2);
	}
	{
		//overloaded functions
		boost::lambda::bind(static_cast<void (*)(int)>(&f), boost::lambda::_1);
		boost::lambda::bind(static_cast<void (test::*)(int)>(&test::f), boost::lambda::_1);
		boost::lambda::bind(static_cast<void (test::*)()>(&test::g), boost::lambda::_1);
		boost::lambda::bind(static_cast<void (test::*)() const>(&test::g), boost::lambda::_1);
		boost::lambda::bind(static_cast<int& (test::*)()>(&test::h), boost::lambda::_1);
		boost::lambda::bind(static_cast<const int& (test::*)() const>(&test::h), boost::lambda::_1);
	}
	{
		std::vector<boolean*> v;
		v.push_back(new boolean(true));
		v.push_back(new boolean(false));
		v.push_back(new boolean(true));
		std::vector<boolean*>::iterator it=
			find_if(v.begin(), v.end(), 
			!boost::lambda::bind(static_cast<bool (boolean::*)() const>(&boolean::is_true),
			boost::lambda::_1)
			);
		assert(it!=v.end());
		assert(!(*it)->is_true());
	}
	{
		base_* s=new sub_();
		assert(boost::lambda::bind(&base_::get_n, boost::lambda::_1)(s)==5);
		assert(*boost::lambda::bind(&base_::get_ptr_n, boost::lambda::_1)(s)==5);
	}
	{
//http://stackoverflow.com/questions/6841680/boostlambda-expression-fails-to-compile-because-of-instantiation-of-abstract-t
		typedef BASE CLASS;	//not compiling
		//typedef SUB CLASS;    //compiles
		
		boost::function< bool (const CLASS::Ptr&)> func;
		func=(boost::lambda::protect(boost::lambda::bind(&CLASS::it, *boost::lambda::_1))(boost::lambda::_1)==3);
		//func=(boost::lambda::protect(boost::lambda::bind(&CLASS::it, boost::lambda::bind(&CLASS::Ptr::get, boost::lambda::_1)))(boost::lambda::_1)==3);
	}
	{
		std::vector<int*> v;
		std::vector<int*>::const_iterator it;
		
		v.push_back(new int(0));
		v.push_back(new int(1));
		v.push_back(new int(2));
		it=std::find_if(v.begin(), v.end(), boost::lambda::bind(g, boost::lambda::_1, 1));
		assert(it!=v.end());
		assert(*(*it)==1);
	}
	{
		std::vector<sub_*> v;
		//std::vector<sub_*>::const_iterator it;
		
		v.push_back(new sub_());
		v.push_back(new sub_());
		v.push_back(new sub_());
		
		assert(*(v[0]->is(5))==5);
		assert(*(boost::lambda::bind(&sub_::is, v[0], 5)())==5);
		assert(*(boost::lambda::bind(&sub_::is, v[0], 6)())==-1);
	}
	{
		std::vector<nitesh*> v;
		std::vector<nitesh*>::const_iterator it;
		v.push_back(new nitesh());
		it=std::find_if(v.begin(), v.end(),
			*boost::lambda::bind(&nitesh::f, boost::lambda::_1, 1)==1);
		assert(it!=v.end());
	}
	{
		std::set<base*> set;
		set.insert(new base(0));
		set.insert(new base(1));
		std::set<base*>::const_iterator it=std::find_if(set.begin(), set.end(),
			*boost::lambda::bind(&base::get_n, boost::lambda::_1)==1);
		assert(it!=set.end());
	}
	return 0;
}
