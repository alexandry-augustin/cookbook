#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

class Base
{
	int m_n;

public:
	Base(int n=0):
		m_n(n)
	{
	}

	int getN() const { return m_n; }
	void setN(int n) { m_n=n; }
};

struct IsEven:
	public std::unary_function<Base*, bool>
{
	bool operator()(Base* base) const
	{
		assert(base!=NULL);

		return (base->getN()%2==0);
	}
};

struct IsOdd
//	: public std::unary_function<Base*, bool>
{
	bool operator()(Base* base) const
	{
		assert(base!=NULL);
		
		return (base->getN()%2!=0);
	}
};

int main() 
{
	std::vector<Base*> v;
	for(int i=0; i<10; ++i) v.push_back(new Base(i));

	{
		std::vector<Base*>::iterator it;
		it=find_if(v.begin(), v.end(), IsOdd());
		assert(it!=v.end());  //returns v.end() if not found
		assert((*it)->getN()==1);
	}
	
	return 0;
}
