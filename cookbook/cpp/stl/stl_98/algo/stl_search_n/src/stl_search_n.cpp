#include <iostream>
#include <cassert>
#include <numeric>
#include <vector>
#include <algorithm>

class base
{
	int _n;
public:
	base(int n=0): _n(n) { }
	int get_n() const { return _n; }
	void set_n(int n) { _n=n; }
};

bool mypredicate(int i, int j)
{
	return (i==j);
}

int main() 
{
	{
		int a[]={10,20,30,30,20,10,10,20};
		std::vector<int> v(a,a+8);
		std::vector<int>::iterator it;

		it=std::search_n(v.begin(), v.end(), 2, 30);
		assert(it!=v.end());
		int pos=it-v.begin();
		assert(pos==2);
	}
	{
		int a[]={10,20,30,30,20,10,10,20};
		std::vector<int> v(a,a+8);
		std::vector<int>::iterator it;
		
		it=std::search_n(v.begin(), v.end(), 2, 10, mypredicate);
		assert(it!=v.end());
		int pos=it-v.begin();
		assert(pos==5);
	}
	return 0;
}
