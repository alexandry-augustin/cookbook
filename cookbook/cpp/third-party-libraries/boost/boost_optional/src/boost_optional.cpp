#include <iostream>
#include <cassert>
#include <string>
#include <boost/optional.hpp>
#include <boost/noncopyable.hpp>
//---------------------------------------------------------
//sample implementation:
//
//template <typename T>
//class optional {
//public:
//	optional(): init_(false) {}
//	optional(const T &val) :init_(true)
//	{ 
//		construct(val);
//	}
//	optional(const optional<T> &opt) :init_(opt.init_)
//	{
//		if (init_) construct(opt.get());
//	}
//	optional &operator=(const optional<T> &opt)
//	{
//		destruct();
//		if (init_ = opt.init_)
//			construct(opt.get());
//		return *this;
//	}
//	~optional()
//	{
//		destruct();
//	}
//	operator bool () const
//	{ 
//		return init_; 
//	}
//	T &operator*()
//	{
//		return get(); // undefined if not initialized            
//	}
//	const T &operator * () const
//	{
//		return get(); // undefined if not initialized
//	}
//protected:
//	void *storage () { return data_; }
//	const void *storage () const { return data_; }
//
//	T &get () { return *static_cast<T*>(storage()); }
//	const T &get () const { return *static_cast<const T*>(storage()); };
//
//	void destruct () { if (init_) get().~T(); init_ = false; }
//	void construct (const T &data) { new (storage()) T(data); }
//
//	bool init_;
//	char data_[sizeof(T)];
//};
//---------------------------------------------------------
class base_00: public boost::noncopyable { };
//---------------------------------------------------------
template <typename T> 
T const& safe_get(boost::optional<T> const& opt) 
{ 
	if(!opt)
		throw std::exception(); 
	return *opt; 
} 
template <typename T> 
T& safe_get(boost::optional<T>& opt) 
{ 
	if(!opt)
		throw std::exception(); 
	return *opt; 
} 
//---------------------------------------------------------
boost::optional<int> f_00(bool empty)
{
	//boost::optional<int> value;
	//return value;
	if(empty)
		return boost::optional<int>();
	else
		return boost::optional<int>(0);
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		boost::optional<int> opt_00;
		boost::optional<int> opt_01(6);

		assert(!opt_00); //not initialized
		opt_00.reset(4);
		assert(opt_00); //initialized
		assert(opt_00.get()==4);
		assert(*opt_00==4);

		assert(opt_01);
		assert(opt_01.get()==6);
	}
	{
		int n=5;
		boost::optional<int> opt_00(n);

		opt_00.get()=7;
		assert(opt_00.get()==7);
		assert(n==5);
	}
	{
		boost::optional<int> opt(5);

		assert(opt);
		opt.reset();
		assert(!opt);

	}
	{
		boost::optional<int> opt_00;
		//opt_00.get(); //will assert(false);
	}
	{
		assert(!f_00(true));
		assert(f_00(false));
	}
	{
		//boost::optional does not work with boost::noncopyable
		boost::optional<base_00> opt;
		//opt.reset(base_00()); //compile error
	}
	return 0;
}
