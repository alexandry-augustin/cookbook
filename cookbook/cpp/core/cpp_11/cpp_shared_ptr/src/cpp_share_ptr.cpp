#include <iostream>
#include <cassert>
#include <memory>

// /!\ return smart pointer by value (otherwise use_count is not incremented)

// shared_ptr()
// explicit shared_ptr(const std::share_ptr&)
// ~shared_ptr()
// operator=()
// void swap()
// void reset()
// T* get()
// T& operator*()
// T* operator->()
// long use_count()
// bool unique()
// operator bool()

class base
{
	int 	_n;
public:
	typedef std::shared_ptr<base> base_ptr;
	
	base(int n): _n(n) { /*std::cout<<"[base::base] ["<<_n<<"]"<<std::endl;*/ }
	~base() { /*std::cout<<"[base::~base] ["<<_n<<"]"<<std::endl;*/ }
	int get_n() const { return _n; }
	int set_n(int n) { _n=n; }
};

int f_00(std::shared_ptr<base> ptr)
{
	//ptr.use_count() increase by 1

	return ptr.use_count();
}

int f_01(const std::shared_ptr<base>& ptr)
{
	return ptr.use_count();
}

std::shared_ptr<base> f_02(const base& b)
{
	return std::make_shared<base>(b);
}

void life_cycle_test()
{
	{
		//reset()
		std::shared_ptr<base> ptr_00(new base(5));

		assert(ptr_00.get()!=0);
		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);

		ptr_00.reset(); //use_count()==0 => ~base() called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
	}
	{
		//reset()
		std::shared_ptr<base> ptr_00(new base(1));

		assert(ptr_00.use_count()==1);
		ptr_00.reset(new base(2)); //use_count()==0 => ~base() called

		assert(ptr_00.get()!=0);
		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
	}
	{
		//reset()
		std::shared_ptr<base> ptr_00(new base(5));
		std::shared_ptr<base> ptr_01(ptr_00);

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);

		ptr_00.reset(); //use_count()>0 => ~base() not called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_01.reset(); //use_count()==0 => ~base() called

		assert(ptr_01.get()==0);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==0);
	}
	{
		//swap()
		std::shared_ptr<base> ptr_00(new base(1));
		std::shared_ptr<base> ptr_01(new base(2));

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_00.swap(ptr_01); //swap ptr and use_count

		assert(ptr_00->get_n()==2);
		assert(ptr_01->get_n()==1);

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);
	}
	{
		//swap()
		std::shared_ptr<base> ptr_00(new base(1));
		std::shared_ptr<int> ptr_01(new int(2));

		//ptr_00.swap(ptr_01); //nok
	}
	{
		//operator=()
		std::shared_ptr<base> ptr_00(new base(1));
		std::shared_ptr<base> ptr_01(new base(2));

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
		assert(ptr_01.unique()==true);
		assert(ptr_01.use_count()==1);

		ptr_00=ptr_01; //ptr_01.use_count()==0 => ~base() called

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);
	}
	{
		//operator=()
		std::shared_ptr<base> ptr_00(new base(1));
		std::shared_ptr<base> ptr_01(ptr_00);

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);

		ptr_00=ptr_01; //no effects

		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==2);
		assert(ptr_01.unique()==false);
		assert(ptr_01.use_count()==2);
	}
}

void make_shared_test()
{
	{
		base b(4);
		std::shared_ptr<base> ptr_00=std::make_shared<base>(b);

		assert(ptr_00->get_n()==4);
	}
	{
		std::shared_ptr<base> ptr_00=std::make_shared<base>(8);

		assert(ptr_00->get_n()==8);
	}
	{
		std::shared_ptr<base> ptr_00=std::make_shared<base>(base(9));

		assert(ptr_00->get_n()==9);
		assert((*f_02(base(8))).get_n()==8);
		assert(f_02(base(8))->get_n()==8);
	}
}

void misc_test()
{
	{
		std::shared_ptr<base> ptr_00; //new is not called
		std::shared_ptr<base> ptr_01(new base(0));

		assert(ptr_00.unique()==false);
		assert(ptr_01.unique()==true);

		std::shared_ptr<base> ptr_02(ptr_01);

		assert(ptr_01.unique()==false);
		assert(ptr_02.unique()==false);
	}
	{
		//bool conversion
		std::shared_ptr<base> ptr_00; //new is not called
		std::shared_ptr<base> ptr_01(new base(0));

		assert(ptr_00==false);
		//assert(ptr_01==true);
	}
	{
		std::shared_ptr<base> ptr_00; //new is not called

		assert(ptr_00.get()==0);
		assert(ptr_00.unique()==false);
		assert(ptr_00.use_count()==0);
	}
	{
		std::shared_ptr<base> ptr_00(new base(5));

		assert(ptr_00.get()!=0);
		assert(ptr_00->get_n()==5);
		assert((*ptr_00.get()).get_n()==5);
	}
	{
		base::base_ptr ptr_00(new base(1));
		std::shared_ptr<int> ptr_01(new int(2));

		ptr_00->set_n(*ptr_01);

		assert(ptr_00->get_n()==2);
	}
	{
		std::shared_ptr<base> ptr_00(new base(1));
		//std::shared_ptr<std::shared_ptr<base> > ptr_01(ptr_00);
	}
	{
		base::base_ptr ptr_00(new base(1));

		assert(ptr_00.use_count()+1==f_00(ptr_00));
		//or
		int use_count=ptr_00.use_count();
		assert(f_00(ptr_00)==use_count+1);

		assert(ptr_00.use_count()==f_01(ptr_00));
		assert(f_01(ptr_00)==ptr_00.use_count());

		assert(ptr_00.unique()==true);
		assert(ptr_00.use_count()==1);
	}
}

int main()
{
	misc_test();
	life_cycle_test();
	make_shared_test();

	return 0;
}
