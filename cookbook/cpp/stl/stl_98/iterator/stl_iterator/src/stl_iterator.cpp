#include <iterator> //std::distance
#include <vector>
#include <list>
#include <iostream>
#include <cassert>
#include <iostream>

typedef std::vector<int> vector_t;
typedef std::list<int> list_t;

void comparison()
{
	//http://www.cplusplus.com/reference/iterator/
	{
		int a[]={ 0, 1, 2, 3, 4, 5};
		vector_t v(a, a+6);
		vector_t::iterator it;

		it=v.begin();
		--it;
		assert(it<v.begin());
	}
	{
		int a[]={ 0, 1, 2, 3, 4, 5};
		list_t l(a, a+6);
		list_t::iterator it;

		it=--l.begin();
		//assert(it<l.begin()); //not support by bidirectional iterators
		//assert(std::distance(l.begin(), it)<0);
		
		std::cout<<std::distance(l.begin(), it)<<' '<<std::distance(it, l.begin());
	}
}

int main()
{
	comparison();
	{
		int a[]={ 0, 1, 2, 3, 4, 5};
		vector_t v(a, a+6);

		for(vector_t::iterator it=v.begin(); it!=v.end(); ++it)
		{
			if(std::distance(v.begin(), it)==v.size()-1)
				assert(*it==5);
		}
		for(vector_t::const_iterator it=v.begin(); it!=v.end(); ++it)
		{
			if(std::distance<vector_t::const_iterator>(v.begin(), it)==v.size()-1)
				assert(*it==5);
		}
	}
	{
		int a[]={ 0, 1, 2, 3, 4, 5};
		vector_t v(a, a+6);
		vector_t::iterator it;

		it=v.begin();
		--it;
		assert(it<v.begin());
	}
	return 0;
}
