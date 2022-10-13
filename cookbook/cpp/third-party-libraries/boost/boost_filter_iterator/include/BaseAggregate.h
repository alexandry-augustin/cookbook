#ifndef BASEAGGREGATE_H
#define BASEAGGREGATE_H

#include <vector>
#include <boost/iterator/filter_iterator.hpp>

class Base;

template <typename T>
class BaseAggregate
{
	std::vector<T>	_v;

public:
//	typedef boost::filter_iterator<TPredicate, std::vector<Base* /*T FIXME*/>::iterator>

	BaseAggregate()
	{
	}

	void add(Base* b)
	{
		_v.push_back(b);
	}

	template <typename TPredicate>
	boost::filter_iterator<TPredicate, std::vector<Base* /*T FIXME*/>::iterator> iterator_begin(const TPredicate& p) 
	{
		return boost::make_filter_iterator<TPredicate>(p, _v.begin(), _v.end());
	}
	template <typename TPredicate>
	boost::filter_iterator<TPredicate, std::vector<Base* /*T FIXME*/>::iterator> iterator_end(const TPredicate& p) 
	{
		return boost::make_filter_iterator<TPredicate>(p, _v.end(), _v.end());
	}



	template <typename TPredicate>
	boost::filter_iterator<TPredicate, std::vector<Base* /*T FIXME*/>::iterator> iterator_begin_() 
	{
		return boost::make_filter_iterator<TPredicate>(_v.begin(), _v.end());
	}
	template <typename TPredicate>
	boost::filter_iterator<TPredicate, std::vector<Base* /*T FIXME*/>::iterator> iterator_end_() 
	{
		return boost::make_filter_iterator<TPredicate>(_v.end(), _v.end());
	}
};

#endif
