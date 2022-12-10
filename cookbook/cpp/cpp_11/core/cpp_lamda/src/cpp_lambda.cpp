#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cassert>

void f_00(std::function<void (int)> handler)
{
	handler(5);
}

class base_00
{
	virtual void f_00(int n)=0;
};

void f_01(const base_00& b)
{
}

int main()
{
	{
		std::vector<int> v;
		for(int i=0; i<10; ++i)
			v.push_back(i);
		int evenCount=0;
		std::for_each(v.begin(), v.end(),
			[&evenCount] (int n)
			{
				std::cout<<n;
				if(n%2==0)
				{
					std::cout<<" is even "<<std::endl;
					++evenCount;
				}
				else
					std::cout<<" is odd "<<std::endl;
			}
		);
	}
	{
		f_00([] (int n) { assert(n==5); });

		int n_00=5;
		f_00([&n_00] (int n) { n_00=n; });
		assert(n_00==5);

		//f_01([] (int n) { }); //nok: cannot use lambda to implement interfaces
	}
	return 0;
}
