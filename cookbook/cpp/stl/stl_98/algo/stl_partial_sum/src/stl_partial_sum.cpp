#include <iostream>
#include <functional>
#include <vector>
#include <numeric>  //std::partial_sum

int myop(int x, int y) { return x+y+1; }

int main() 
{
	int a[]={ 1, 2, 3, 4, 5 };
	int res[5];
	
	std::partial_sum(a, a+5, res);
	for(int i=0; i<5; i++) 
		std::cout<<res[i]<<' ';
	std::cout<<std::endl;
	
	std::partial_sum(a, a+5, res, std::multiplies<int>());
	for (int i=0; i<5; i++) 
		std::cout<<res[i]<<' ';
	std::cout<<std::endl;
	
	std::partial_sum(a, a+5, res, myop);
	for(int i=0; i<5; i++) 
		std::cout<<res[i]<<' ';
	std::cout<<std::endl;
	
	std::vector<int> v(a, a+5), res2(v);
	std::partial_sum(v.begin(), v.end(), res2.begin());
	for(unsigned int i=0; i<res2.size(); i++) 
		std::cout<<res2[i]<<' ';
	std::cout<<std::endl;
	
	return 0;
}
