#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Remove consecutive duplicates in range

bool myfunction (int i, int j) { return (i==j); }

template<typename T>
void print(const T& t, unsigned int size)
{
	for(unsigned int i=0; i<size; ++i)
		cout<<t[i]<<" ";
	cout<<endl;
}
void main()
{
	int a[] = {10, 20, 20, 20, 30, 30, 20, 20, 10};
	vector<int> v(a, a+9);
	vector<int>::iterator it;

	print(v, v.size());
	it = unique(v.begin(), v.end());
	v.resize(it - v.begin());
	//or
	//v.erase(unique(v.begin(), v.end()), v.end());

	//unique(v.begin(), v.end(), myfunction);
	print(v, v.size());



	int* p = unique(a, a+9);
	int size=p-a;
	print(a, size);

}