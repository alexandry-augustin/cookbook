#include <cassert>
#include <iostream>
#include <list>
#include <array>
#include <functional>

class base_00
{
	int _n;
public:
	base_00(int n=0): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

class base_01
{
	int _n;
public:
	base_01(int n=0): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

int main()
{
	{
		typedef std::function<void (int)>	set_t;
		typedef std::function<int ()>		get_t;

		base_00 b;	
		set_t set=std::bind(&base_00::set, &b, std::placeholders::_1);
		get_t get=std::bind(&base_00::get, &b);

		set(9);
		assert(get()==9);
	}
	{
		typedef std::function<void (int)>	set_t;
		typedef std::function<int ()>		get_t;

		std::array<base_00, 3> a;
		std::list<set_t> set_l;
		std::list<get_t> get_l;

		for(const base_00& b: a)
			get_l.push_back(std::bind(&base_00::get, &b));

		for(base_00& b: a)
			set_l.push_back(std::bind(&base_00::set, &b, std::placeholders::_1));

		for(auto f: set_l)
			f(5);

		for(auto f: get_l)
			assert(f()==5);
	}
	{
		typedef std::function<void (int)>	set_t;
		typedef std::function<int ()>		get_t;

		base_00 b_00;
		base_01 b_01;
		std::list<set_t> set_l;
		std::list<get_t> get_l;

		get_l.push_back(std::bind(&base_00::get, &b_00));
		get_l.push_back(std::bind(&base_01::get, &b_01));

		set_l.push_back(std::bind(&base_00::set, &b_00, std::placeholders::_1));
		set_l.push_back(std::bind(&base_01::set, &b_01, std::placeholders::_1));

		for(auto f: set_l)
			f(5);

		for(auto f: get_l)
			assert(f()==5);
	}
	return 0;
}
