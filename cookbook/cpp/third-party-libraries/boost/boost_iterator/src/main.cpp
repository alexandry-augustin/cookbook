#include <boost/config.hpp>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <cassert>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/cstdlib.hpp> // for boost::exit_success

class Base
{
	int m_n;

public:
	Base(int n)
		: m_n(n)
	{
	}

	int getN() const
	{
		return m_n;
	}
	void setN(int n)
	{
		m_n=n;
	}
};

struct is_positive_number_vector
{
	bool operator()(int x)
	{
		return 0 < x;
	}
};

struct is_positive_number_array
{
	bool operator()(int x)
	{
		return 0 < x;
	}
};

int main()
{
	//array
	
	int a[]={ 0, -1, 4, -3, 5, 8, -2 };
	const int N=sizeof(a)/sizeof(int);
	
	std::copy(a, a+N, std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//examples using make_filter_iterator()
	std::copy(
		boost::make_filter_iterator<is_positive_number_array>(a, a+N),
		boost::make_filter_iterator<is_positive_number_array>(a+N, a+N),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	std::copy(
		boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, a, a+N), 
		boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, a+N, a+N), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//example using filter_iterator
	is_positive_number_array predicate_array;
	boost::filter_iterator<is_positive_number_array, int*> filter_iter_first_array(predicate_array, a, a+N);
	boost::filter_iterator<is_positive_number_array, int*> filter_iter_last_array(predicate_array, a+N, a+N);

	std::copy(filter_iter_first_array, filter_iter_last_array, std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//vector
	
	std::vector<int> v(a, a+N);
	
	std::copy(
		v.begin(),
		v.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//examples using make_filter_iterator()
	std::copy(
		boost::make_filter_iterator<is_positive_number_vector>(v.begin(), v.end()),
		boost::make_filter_iterator<is_positive_number_vector>(v.end(), v.end()),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	std::copy(
		boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, v.begin(), v.end()), 
		boost::make_filter_iterator(
			std::bind2nd(std::greater<int>(), -2)
			, v.end(), v.end()), 
		std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	//example using filter_iterator
//	is_positive_number_vector predicate_vector;
//	boost::filter_iterator<is_positive_number_vector, int*> filter_iter_first_vector(predicate_vector, v.begin(), v.end());
//	boost::filter_iterator<is_positive_number_vector, int*> filter_iter_last_vector(predicate_vector, v.end(), v.end());
//
//	std::copy(filter_iter_first_vector, filter_iter_last_vector, std::ostream_iterator<int>(std::cout, " "));
//	std::cout<<std::endl;
	
	//vector (2)
	
//	std::vector<int> w;
//	for(int i=0; i<5; ++i)
//		v.push_back(new Base(i);
//	
//	std::copy(
//		v.begin(),
//		v.end(),
//		std::ostream_iterator<int>(std::cout, " "));
//	std::cout<<std::endl;
//	
//	//examples using make_filter_iterator()
//	std::copy(
//		boost::make_filter_iterator<is_positive_number_vector>(v.begin(), v.end()),
//		boost::make_filter_iterator<is_positive_number_vector>(v.end(), v.end()),
//		std::ostream_iterator<int>(std::cout, " "));
//	std::cout<<std::endl;
	
	return boost::exit_success;
}