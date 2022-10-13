#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <boost/any.hpp>
//---------------------------------------------------------
template <typename T>
bool contains(const boost::any& any)
{
	return typeid(T)==any.type();
}
//---------------------------------------------------------
struct Formattable
{
	virtual std::string str() const=0;
};
//---------------------------------------------------------
struct A
{
	void f() { std::cout<<"[A::f]"<<std::endl; }
};
//---------------------------------------------------------
struct B
{
	void f() { std::cout<<"[B::f]"<<std::endl; }
};
//---------------------------------------------------------
struct C: public Formattable
{
	/*virtual*/ std::string str() const
	{
		return "[base::str]";
	}
};
//---------------------------------------------------------
void f(boost::any& any)
{
	if(A* pA=boost::any_cast<A>(&any))
		pA->f();
	if(B* pB=boost::any_cast<B>(&any))
		pB->f();
}
//---------------------------------------------------------
void g(boost::any& any)
{
	if(Formattable* pF=boost::any_cast<Formattable*>(any))
		pF->str();
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		int* n=NULL;
		boost::any a(n);
		assert(contains<int*>(a));
		int* m=boost::any_cast<int*>(a);
		assert(m==NULL);
	}
	{
		boost::any a((int*)NULL);
		assert(contains<int*>(a));
		assert(boost::any_cast<int*>(a)==NULL);
	}
	{
		boost::any(5);
		//boost::any("saf"); //nok
		boost::any(std::string("saf"));
	}
	{
		std::vector<boost::any> v;
		v.push_back(A());
		v.push_back(B());
		//v.push_back(B());
		std::for_each(v.begin(), v.end(), f);
		for(int i=0; i<v.size(); ++i)
			std::cout<<"v["<<i<<"] "<<(contains<A>(v[i])?"":"doesn't ")<<"contains A "
				<<"and "<<(contains<B>(v[i])?"":"doesn't ")<<"contains B."<<std::endl;
	}
	{
		std::vector<boost::any> v;
		C* c=new C();
		boost::any any(c);
		v.push_back(any);
		std::for_each(v.begin(), v.end(), g);
	}
	{
		A* pData=new A();
		boost::any* any=new boost::any(*pData);   //create a copy
		A* pData_recovered=new A();
		try
		{
			*pData_recovered=boost::any_cast<A>(*any);
		}
		catch(const boost::bad_any_cast& e)
		{
			std::cout<<e.what()<<std::endl;
		}

		delete pData;
		delete any;
		pData_recovered->f();
		delete pData_recovered;
	}
	{
		boost::any* any=new boost::any(std::string("str"));

		std::string str;
		try
		{
			str=boost::any_cast<std::string>(*any);
		}
		catch(const std::exception& e)
		{
			std::cout<<"Exception: "<<e.what()<<std::endl;
		}
		std::cout<<str<<std::endl;
		delete any;
	}
	{
		A* a=new A();
		boost::any* any=new boost::any(a);

		A* a2=NULL;
		try
		{
			a2=boost::any_cast<A*>(*any);
		}
		catch(const std::exception& e)
		{
			std::cout<<"Exception: "<<e.what()<<std::endl;
		}
		delete any;
		a2->f();
		delete a2;
	}
	{
		int i=5;
		void* p=&i;
		static_cast<double*>(p);  //compiler doesn't complain. Undefined Behavior.
		boost::any any;
		any=i;
		try
		{
			boost::any_cast<double>(any); //throws, which is good
		}
		catch(const std::exception& e)
		{
			std::cerr<<"Exception: "<<e.what()<<std::endl;
		}
	}
	return 0;
}
