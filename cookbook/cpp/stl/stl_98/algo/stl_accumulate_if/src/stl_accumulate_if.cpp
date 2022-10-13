#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

template< typename InputIterator, typename T, typename BinaryOperation, typename UnaryPredicate>
T accumulate_if(InputIterator begin, InputIterator end, T init, BinaryOperation binary_op, UnaryPredicate pred)
{
	T res=init;
	while(begin!=end)
	{
		if(pred(*begin))
			res=binary_op(res, *begin);
		++begin;
	}
	return res;
};

class base
{
	int* _n;
public:
	base(int n=0): _n(new int(n)) {}
	int* get_n() const { return _n; }
	void set_n(int* n) { _n=n; }
	void str() const { std::cout<<(*_n)<<std::endl; }
};

struct Base
{
	int _n;
	Base operator+(const Base& b) const { return Base(_n+b._n); }
	Base(int n): _n(n) { }
};

struct Add_int
{
	int operator()(int accumulation_so_far, int n) const
	{
		return accumulation_so_far+n;
	}
};

struct Add_base
{
	Base* operator()(Base* accumulation_so_far, Base* b) const
	{
		return new Base(accumulation_so_far->_n+b->_n);
	}
};

struct IsOdd
{
	bool operator()(int i) const
	{
		return (i%2!=0);
	}
};

struct BaseIsOdd:
	public std::unary_function<Base*, bool>
{
	bool operator()(Base* b) const
	{
		return (b->_n%2!=0);
	}
};

typedef typename std::map<std::string, base*> map_type;
base* accumulator(base* acc_so_far, map_type::value_type pair)
{
	return new base(*acc_so_far->get_n()+*pair.second->get_n());
}

bool is_odd(map_type::value_type pair)
{
	return (*pair.second->get_n())%2;
}

struct sub
{
	int n;
	sub(int n=0): n(n) {}
};

typedef typename std::map<std::string, sub> sub_map_type;
int acc(int acc_so_far, const sub_map_type::value_type& pair)
{
	return acc_so_far+pair.second.n; 
}

int main()
{
	{
		std::vector<int> v, w;
		std::vector<Base*> x, y, z;
		for(int i=0; i<10; ++i) v.push_back(i);
		for(int i=0; i<10; ++i) x.push_back(new Base(i));
		
		assert(std::accumulate(v.begin(), v.end(),
			int(0), Add_int())==45);
		assert(std::accumulate(x.begin(), x.end(),
			new Base(0), Add_base())->_n==45);
		assert(std::accumulate(x.begin(), x.end(),
			new Base(0), Add_base())->_n==45);
		
		assert(accumulate_if(v.begin(), v.end(),
			int(0), Add_int(), IsOdd())==25);
		assert(accumulate_if(x.begin(), x.end(),
			new Base(0), Add_base(), BaseIsOdd())->_n==25);
		assert(accumulate_if(x.begin(), x.end(),
			new Base(0), Add_base(), std::not1(BaseIsOdd()))->_n==20);
	}
	{
		sub_map_type map;
		sub_map_type::const_iterator it;
		
		map["zero"]=sub(0);
		map["one"]=sub(1);
		map["two"]=sub(2);
		
		assert(std::accumulate(map.begin(), map.end(), 0, acc)==3);
	}
	{
		typedef typename std::map<std::string, base*> map_type;
		map_type map;
		map_type::const_iterator it;
		
		map["zero"]=new base(0);
		map["one"]=new base(1);
		map["two"]=new base(2);
		
		base* res=std::accumulate(map.begin(), map.end(), new base(0), accumulator);
		assert(*res->get_n()==3);
		
		res=accumulate_if(map.begin(), map.end(), new base(0), accumulator, is_odd);
		assert(*res->get_n()==1);
	}
	return 0;
}

