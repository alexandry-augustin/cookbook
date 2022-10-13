#include <iostream>
#include <algorithm>
#include <vector>

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

	int x=1, y=2;
	swap(x,y);
	cout<<"x="<<x<<" y="<<y<<endl;

	int a[]={1,2,3,4};
	vector<int> v(a, a+2), w(a+2, a+4);
	cout<<"v="; print(v, v.size());
	swap(v, w);

	cout<<"v="; print(v, v.size());
	swap(v[0], v[1]);
	//or equivalently using iterators
	iter_swap(v.begin(), v.begin()+1);
	cout<<"v="; print(v, v.size());

	cout<<"v="; print(v, v.size());
	cout<<"w="; print(w, w.size());
	swap(v[0], w[0]);
	//or equivalently using iterators
	iter_swap(v.begin(), w.begin());
	cout<<"v="; print(v, v.size());
	cout<<"w="; print(w, w.size());

	return 0;
}