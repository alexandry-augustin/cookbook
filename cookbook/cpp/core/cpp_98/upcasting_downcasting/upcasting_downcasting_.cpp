#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class base
{
public:
	void fctBase() const
	{
		cout<<"fctBase()"<<endl;
	}
};

class sub: public base
{
public:
	void fctSub() const
	{
		cout<<"fctSub()"<<endl;
	}
};

int main()
{
	base b;
	sub s;

	// upcast - implicit type cast allowed
	//Upcasting: convert derived-class reference or pointer to a base-class.
	//It is always allowed for public inheritance, without an explicit type cast.
	base* pBase=&s;

	// downcast - explicit type case required
	sub* pSub=(sub*)&b;

	pBase->fctBase(); 	//"fctBase()"
	pSub->fctSub(); 	//"fctSub()"

	return 0;
}