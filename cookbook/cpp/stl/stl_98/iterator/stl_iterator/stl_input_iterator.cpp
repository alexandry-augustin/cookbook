#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

template <typename T>
class input_iterator
{
	T a[];

public:
	typedef typename std::iterator_traits<T>::value_type		value_type;
	typedef typename std::iterator_traits<T>::difference_type	difference_type;

	input_iterator(int size)
	{
		a=new T[size];
	}
};

int main__()
{
	{
		int a[]={ 0, 1, 2, 3 };
		std::iterator_traits<int*>::difference_type n=std::distance(a, a+3);
		assert(n==3);
		
		//std::vector<>
	}
	return 0;
}
