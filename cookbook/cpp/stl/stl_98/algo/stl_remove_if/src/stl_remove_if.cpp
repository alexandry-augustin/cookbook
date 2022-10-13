#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>

bool isOdd(int i) { return ((i%2)==1); }

bool isEven(int i) { return !isOdd(i); }

int main()
{
	{
		int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
		int size=sizeof(a)/sizeof(int);
		std::vector<int> v(a, a+size);	
		
		std::copy(a, a+size, std::ostream_iterator<int>(std::cout, " "));
		std::cout<<std::endl;
		
		//The algorithm library provides the "remove" and "remove_if" algorithms for this. 
		//Because these algorithms operate on a range of elements denoted by two forward iterators, 
		//they have no knowledge of the underlying container or collection. 
		//Thus, the elements are not actually removed from the range, merely moved to the end. 
		//When all the removed elements are at the end of the range, 
		//"remove" returns an iterator pointing one past the last unremoved element.

		int *p=std::remove_if(a, a+size, isEven);
		size=p-a;

		std::vector<int>::iterator new_end=std::remove_if(v.begin(), v.end(), isOdd);
		v.erase(new_end, v.end());

		
		//Erase-remove idiom
		//http://en.wikipedia.org/wiki/Erase-remove_idiom

		v.erase(std::remove(v.begin(), v.end(), 5), v.end()); //remove all elements with the value 5
		v.erase(std::remove_if(v.begin(), v.end(), isOdd), v.end()); //remove all odd numbers

		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout<<std::endl;
	}
	
	{
		std::vector<int> v;
		for(int i=0; i<10; ++i) v.push_back(i);
		assert(v.size()==10);
		v.erase(std::remove_if(v.begin(), v.end(), std::bind1st(std::not_equal_to<int>(), 5)), v.end());
		assert(v.size()==1);
	}
	
	return 0;
}
