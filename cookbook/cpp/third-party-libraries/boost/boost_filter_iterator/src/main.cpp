//http://www.codeproject.com/Questions/331444/How-to-use-boost-filter_iterator-as-a-class-member
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <boost/iterator/filter_iterator.hpp>
#include "Base.h"
#include "BaseAggregate.h"

struct IsPositive
{
	bool operator()(int n)
	{
		return n>0;
	}
};

struct BaseIsPositive
{
	bool operator()(Base* b)
	{
		return b->n()>0;
	}
};

struct BaseIsEven
{
	bool operator()(Base* b)
	{
		return (b->n()%2==0);
	}
};

//std::function<bool(uint32_t)> stlfunc= [](uint32_t n){return n%3==0;};

int main()
{
//	std::vector<uint32_t> numbers{11,22,33,44,55,66,77,3,6,9};
//	auto start = boost::make_filter_iterator(stlfunc, numbers.begin(), numbers.end());
//	auto end   = boost::make_filter_iterator(stlfunc, numbers.end()  , numbers.end());
//	auto elem  = std::max_element(start,end);
//	std::cout<<*elem;
	
	int a[]={ 0, -1, 4, -3, 5, 8, -2 };
	const int size=7;
	std::vector<int> int_v(a, a+size);
	std::vector<Base*> base_v;
	for(int i=0; i<10; ++i) base_v.push_back(new Base(i));
	IsPositive isPositive;
	BaseIsPositive baseIsPositive;
	BaseIsEven baseIsEven;
	BaseAggregate<Base*> ba;
	for(int i=0; i<10; ++i) ba.add(new Base(9-i));
	
	// boost::filter_iterator
	boost::filter_iterator<IsPositive, int*> first(isPositive, a, a+size);
	boost::filter_iterator<IsPositive, int*> last(isPositive, a+size, a+size);

	for(boost::filter_iterator<IsPositive, int*> it=first; it!=last; ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	
	std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	for(boost::filter_iterator<IsPositive, std::vector<int>::iterator> it=
			boost::filter_iterator<IsPositive, std::vector<int>::iterator>(isPositive, int_v.begin(), int_v.end());
		it!=boost::filter_iterator<IsPositive, std::vector<int>::iterator>(isPositive, int_v.end(), int_v.end());
		++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	
	{
		typedef boost::filter_iterator<BaseIsPositive, std::vector<Base*>::iterator> base_filter_iterator_type;

		for(base_filter_iterator_type it=base_filter_iterator_type(baseIsPositive, base_v.begin(), base_v.end());
			it!=base_filter_iterator_type(baseIsPositive, base_v.end(), base_v.end());
			++it)
			std::cout<<(*it)->n()<<" ";
		std::cout<<std::endl;
	}
	
	// boost::make_filter_iterator
	boost::filter_iterator<IsPositive, int*> make_first=boost::make_filter_iterator<IsPositive>(a, a+size);
	boost::filter_iterator<IsPositive, int*> make_last=boost::make_filter_iterator<IsPositive>(a+size, a+size);

	for(boost::filter_iterator<IsPositive, int*> it=make_first; it!=make_last; ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	
	{
		typedef boost::filter_iterator<BaseIsPositive, std::vector<Base*>::iterator> base_filter_iterator_type;

		for(base_filter_iterator_type it=boost::make_filter_iterator<BaseIsPositive>(base_v.begin(), base_v.end());
			it!=boost::make_filter_iterator<BaseIsPositive>(base_v.end(), base_v.end());
			++it)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
	}
	
	std::copy(boost::make_filter_iterator<IsPositive>(a, a+size),
		boost::make_filter_iterator<IsPositive>(a+size, a+size),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//get n>-2
//	boost::filter_iterator<std::greater<int>(), int*> make_first_=boost::make_filter_iterator(std::bind2nd(std::greater<int>(), -2), a, a+size);
//	boost::filter_iterator<std::greater<int>(), int*> make_last_=boost::make_filter_iterator(std::bind2nd(std::greater<int>(), -2), a+size, a+size);
//
//	for(boost::filter_iterator<std::greater<int>(), int*> it=make_first_; it!=make_last_; ++it)
//		std::cout<<*it<<" ";
	
	std::copy(
		boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, a, a+size)
		, boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, a+size, a+size)
		, std::ostream_iterator<int>(std::cout, " ")
	);
	std::cout<<std::endl;
	
	for(boost::filter_iterator<BaseIsEven, std::vector<Base*>::iterator> it=ba.iterator_begin_<BaseIsEven>();
		it!=ba.iterator_end_<BaseIsEven>();
		++it)
		std::cout<<(*it)->n()<<"_";
	std::cout<<std::endl;
	
	for(boost::filter_iterator<BaseIsEven, std::vector<Base*>::iterator> it=ba.iterator_begin(baseIsEven);
		it!=ba.iterator_end(baseIsEven);
		++it)
		std::cout<<(*it)->n()<<"_";
	std::cout<<std::endl;
	
	return 0;
}