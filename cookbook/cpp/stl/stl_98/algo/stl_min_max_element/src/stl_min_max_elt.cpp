#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfn(int i, int j) { return i<j; }

struct myclass 
{
  bool operator() (int i,int j) { return i<j; }
} myobj;

int main () 
{
	int a[] = {3,7,2,5,6,4,9};

	cout << "The smallest element is " << *min_element(a, a+7) << endl;
	cout << "The largest element is " << *max_element(a,a+7) << endl;

	cout << "The smallest element is " << *min_element(a,a+7,myfn) << endl;
	cout << "The largest element is " << *max_element(a,a+7,myfn) << endl;


	cout << "The smallest element is " << *min_element(a,a+7,myobj) << endl;
	cout << "The largest element is " << *max_element(a,a+7,myobj) << endl;
	
	
	vector<int> v(a, a+7);

	int max=*min_element(v.begin(), v.end());
	int min=*max_element(v.begin(), v.end());
	cout<<min<<endl;
	cout<<max<<endl;

	//cout << "The smallest element is " << *min_element(v.begin(),a+7,myfn) << endl;
	//cout << "The largest element is " << *max_element(v.begin(),a+7,myfn) << endl;

	//cout << "The smallest element is " << *min_element(v.begin(),a+7,myobj) << endl;
	//cout << "The largest element is " << *max_element(v.begin(),a+7,myobj) << endl;

	return 0;
}