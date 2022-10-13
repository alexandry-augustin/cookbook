#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

int main() 
{
	int a[]={ 10, 20, 30 ,40 };
	int *p;
	int key=20;
	std::vector<int> v(a, a+4);
	std::vector<int>::iterator it;
	
	p=std::find(a, a+4, key);
	assert(p!=(a+4));
	
	it=find(v.begin(), v.end(), key);  //returns v.end() if not found
	assert(it!=v.end());
	
	return 0;
}
