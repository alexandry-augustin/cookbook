#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void print(const T& t, unsigned int size)
{
	for(unsigned int i=0; i<size; ++i)
		std::cout<<t[i]<<" ";
	std::cout<<std::endl;
}

bool IsOdd (int i)
{
	return (i%2)==1;
}

int main ()
{
	std::vector<int> v;
	std::vector<int>::iterator it, bound;
	
	for(int i=1; i<10; ++i) v.push_back(i);
	for(it=v.begin(); it!=v.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	
	//bound=partition (v.begin(), v.end(), IsOdd);
	//stable_partition: unlike function partition, the relative order of elements within each group is preserved.
	bound=stable_partition(v.begin(), v.end(), IsOdd); 
	
	//odd members
	for(it=v.begin(); it!=bound; ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	//even members
	for(it=bound; it!=v.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	
	return 0;
}
