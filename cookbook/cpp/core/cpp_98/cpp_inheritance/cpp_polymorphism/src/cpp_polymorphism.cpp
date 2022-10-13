#include <iostream>
#include <vector>
#include <sstream>
#include <string>

/*
Singly-rooted hierarchy/Object-based hierarchy

                       			base
                                         /\
                                      sub1 sub2
                                        /  \
                                    subsub
*/

class base
{
protected:
	int _a;
public:
	base(int a): _a(a) 
	{
		std::cout<<"base::base()"<<std::endl; 
		std::cout<<str()<<std::endl;
	}
	virtual ~base()
	{ 
		std::cout<<"base::~base()"<<std::endl; 
		std::cout<<str()<<std::endl;
	}

	virtual std::string str() const
	{
		std::stringstream ss;
		ss<<"base::_a="<<_a;
		return ss.str();
	}
};

class sub1: public base
{
public:
	sub1(int a): base(a)
	{
		std::cout<<"sub1::sub1()"<<std::endl; 
	}
	~sub1()
	{ 
		std::cout<<"sub1::~sub1()"<<std::endl;
	}

	/*virtual*/ std::string str() const
	{
		std::stringstream ss;
		ss<<"sub1::_a="<<_a;

		return ss.str();
	}
};

class sub2: public base
{
public:
	sub2(int a): base(a)
	{
		std::cout<<"sub2::sub2()"<<std::endl; 
	}
	~sub2()
	{ 
		std::cout<<"sub2::~sub2()"<<std::endl;
	}

	/*virtual*/ std::string str() const
	{
		std::stringstream ss;
		ss<<"sub2::_a="<<_a;

		return ss.str();
	}
};

class subsub: public sub1
{
public:
	subsub(int a): sub1(a)
	{
		std::cout<<"subsub::subsub()"<<std::endl; 
	}
	~subsub()
	{ 
		std::cout<<"subsub::~subsub()"<<std::endl;
	}

	/*virtual*/ std::string str() const
	{
		std::stringstream ss;
		ss<<"subsub::_a="<<_a;

		return ss.str();
	}
};

int main()
{
	{
		/*base b;
		sub s;
		subsub ss;*/
		base* b=new base(0);
		sub1* s1=new sub1(1);
		sub2* s2=new sub2(2);
		subsub* ss=new subsub(11);
		
		std::cout<<s1->str()<<std::endl;	//Derived::fct() is called. Called using late-binding
		delete s1;				//Derived::fct() is not called (even if fct() is virtual). No late binding for destructors
		
		for(int i=0; i<80; ++i) std::cout<<"=";
		
		s1=new sub1(1);
		base* basePtr[]={ b, s1, ss }; //upcasting

		for(int i=0; i<3;++i)
			std::cout<<basePtr[i]->str()<<std::endl;

		for(int i=0; i<80; ++i) std::cout<<"=";
		
		sub1* subPtr[]={s1, ss};
		for(int i=0; i<2;++i)
			std::cout<<subPtr[i]->str()<<std::endl;

		for(int i=0; i<80; ++i) std::cout<<"=";
		
		std::vector<base*> v;
		v.push_back(new base(0));
		v.push_back(new sub1(1)); //upcasting
		v.push_back(new sub2(2)); //upcasting
		v.push_back(new subsub(11)); //upcasting

		for(unsigned int i=0; i<v.size(); ++i)
			std::cout<<v[i]->str()<<std::endl;

		v.clear();
	}
	{
		//using references
		sub1 s(0);
		base& b=s;
	}
}
