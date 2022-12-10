#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
void print(const T& t, unsigned int size)
{
	for(unsigned int i=0; i<size; ++i)
		cout<<t[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[]={ 9, 8, 7, 6, 5, 4 };
	print(a, 6);
	rotate(a, a+2, a+6); //new first element is a[2]
	print(a, 6);
	
	vector<int> v(a, a+6);
	print(v, v.size());
	rotate(v.begin(), v.begin()+2, v.end()); //new first element is v[2]
	print(v, v.size());

	return 0;
}
