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
	int a[]={6, 7, 3, 6, 5, 7};
	vector<int> v(a, a+6);

	int b[]={4, 2, 8, 1, 3};
	vector<int> w(b, b+5);

	vector<int> res(v.size()+w.size());

	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	//crash without sorting?!
	merge(v.begin(), v.end(), w.begin(), w.end(), res.begin());

	print(res, res.size());
	// without sorting
	res.clear();
	v.assign(a, a+6);
	w.assign(b, b+5);
	//res.reserve(v.size()+w.size()); //only for optimisation

	res.insert(res.end(), v.begin(), v.end());
	res.insert(res.end(), w.begin(), w.end());

	print(res, res.size());
	// without sorting
	res.clear();
	std::back_insert_iterator<vector<int> > it(res);

	copy(v.begin(), v.end(), it);
	copy(w.begin(), w.end(), it);

	print(res, res.size());

	return 0;
}