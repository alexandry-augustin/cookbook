#include <iostream>
#include <cassert>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
//---------------------------------------------------------
//pass shared pointer by value in function (will incerement ref_count).
//return smart pointer by value (otherwise ref_count is not incremented).
//---------------------------------------------------------
class base_00
{
	int 	_n;
public:
	typedef boost::shared_ptr<base_00> base_ptr;
	
	explicit base_00(int n): _n(n) { }
	explicit base_00(int n, int m): _n(n+m) { }
	explicit base_00(const base_00& b): _n(b._n) { }
	~base_00() { }
	int get() const { return _n; }
	int set(int n) { _n=n; }
};
//---------------------------------------------------------
struct base_01: public boost::enable_shared_from_this<base_01>
{
	boost::shared_ptr<base_01> get()
	{
		return shared_from_this();
	}
};
//---------------------------------------------------------
struct base_02 : public base_01
{
};
//---------------------------------------------------------
void f_00(boost::shared_ptr<base_00> ptr)
{
	//use_count() will increase by 1
	//std::cout<<ptr.use_count()<<std::endl;
}
//---------------------------------------------------------
boost::shared_ptr<base_00> f_01(const base_00& b)
{
	return boost::make_shared<base_00>(b);
}
//---------------------------------------------------------
void life_cycle_test()
{
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(5));

		assert(ptr_00.get()!=0);
		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);

		ptr_00.reset(); //use_count()==0 => ~base_00() called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(1));

		ptr_00.reset(new base_00(2)); //use_count()==0 => ~base_00() called

		assert(ptr_00.get()!=0);
		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(1));
		boost::shared_ptr<base_00> ptr_01(new base_00(2));

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_00.swap(ptr_01); //swap ptr and ref_count

		assert(ptr_00->get()==2);
		assert(ptr_01->get()==1);

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(1));
		boost::shared_ptr<base_00> ptr_01(new base_00(2));

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_00=ptr_01; //ptr_01.use_count()==0 => ~base_00() called

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(5));
		boost::shared_ptr<base_00> ptr_01(ptr_00);

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);

		ptr_00.reset(); //use_count()>0 => ~base_00() not called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_01.reset(); //use_count()==0 => ~base_00() called

		assert(ptr_01.get()==0);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==0);
	}
}
//---------------------------------------------------------
void make_shared_test()
{
	{
		boost::shared_ptr<base_00> ptr_00=boost::make_shared<base_00>(8); //call the appropriate constructor

		assert(ptr_00->get()==8);
	}
	{
		boost::shared_ptr<base_00> ptr_00=boost::make_shared<base_00>(4, 4); //call the appropriate constructor

		assert(ptr_00->get()==8);
	}
	{
		base_00 b(4);
		boost::shared_ptr<base_00> ptr_00=boost::make_shared<base_00>(b); //call copy constructor

		assert(ptr_00->get()==4);
	}
	{
		boost::shared_ptr<base_00> ptr_00=boost::make_shared<base_00>(base_00(9)); //call copy constructor

		assert(ptr_00->get()==9);
		assert((*f_01(base_00(8))).get()==8);
		assert(f_01(base_00(8))->get()==8);
	}
}
//---------------------------------------------------------
void misc_test()
{
	{
		boost::shared_ptr<base_00> ptr_00; //new is not called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(5));

		assert(ptr_00.get()!=0);
		assert(ptr_00->get()==5);
		assert((*ptr_00.get()).get()==5);
	}
	{
		base_00::base_ptr ptr_00(new base_00(1));
		boost::shared_ptr<int> ptr_01(new int(2));

		ptr_00->set(*ptr_01);

		assert(ptr_00->get()==2);
	}
	{
		boost::shared_ptr<base_00> ptr_00(new base_00(1));
		//boost::shared_ptr<boost::shared_ptr<base_00> > ptr_01(ptr_00);
	}
	{
		base_00::base_ptr ptr_00(new base_00(1));

		f_00(ptr_00);

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
	}
}
//---------------------------------------------------------
void enable_shared_from_this_test()
{
	{
		base_01 b_01;
		bool error=false;
		try
		{
			//can't use shared_from_this until the object is actually managed by shared pointer
			b_01.get(); //will throws
		}
		catch(const boost::bad_weak_ptr& e)
		{
			error=true;
		}
		assert(error);
	}
	{
		boost::shared_ptr<base_01> b_01=boost::shared_ptr<base_01>(new base_01());
		bool error=false;
		try
		{
			b_01->get(); //will not throws
		}
		catch(const boost::bad_weak_ptr& e)
		{
			error=true;
		}
		assert(!error);
	}
	{
		boost::shared_ptr<base_02> b_01=boost::shared_ptr<base_02>(new base_02());
		bool error=false;
		try
		{
			b_01->get(); //will not throws
		}
		catch(const boost::bad_weak_ptr& e)
		{
			error=true;
		}
		assert(!error);
	}
}
//---------------------------------------------------------
int main()
{
	misc_test();
	life_cycle_test();
	make_shared_test();
	enable_shared_from_this_test();
	return 0;
}
