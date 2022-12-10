#include <iostream>     // std::cout
#include <algorithm>    // std::set_difference, std::sort
#include <vector>       // std::vector

struct Base
{
	int m_n;

	Base(int n)
		: m_n(n)
	{
	}
};

int main()
{
	int a[] = { 5, 10, 15, 20, 25 };
	int b[] = { 50, 40, 30, 20, 10 };
	std::vector<int> v(10);	// 0  0  0  0  0  0  0  0  0  0
	std::vector<int>::iterator it;

	//The elements in the ranges shall already be ordered according to this same
	//criterion (operator< or comp). The resulting range is also sorted according to this.
	std::sort(a, a+5);     //  5 10 15 20 25
	std::sort(b, b+5);   // 10 20 30 40 50

	it=std::set_difference (a, a+5, b, b+5, v.begin()); //  5 15 25  0  0  0  0  0  0  0
	
	v.resize(it-v.begin()); //  5 15 25

	for(it=v.begin(); it!=v.end(); ++it)
		std::cout<<' '<<*it;
	std::cout<<std::endl;
	
	std::vector<Base*> w;
	w.push_back(new Base(5));
	w.push_back(new Base(4));
	
	return 0;
}
