#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cassert>

class base
{
public:
	base(int n_): n(n_) {}
	int n;

	std::string str() const
	{
		std::stringstream ss;
		ss<<n;

		return ss.str();
	}
};

//class odd_iterator: public std::iterator<base>
//{
//};

class baseGroup
{
	std::vector<base>			m_v;
	std::vector<base>::const_iterator	m_const_it;
	std::vector<base>::iterator		m_it;
public:
	baseGroup(): m_it(m_v.begin()) {}

	std::vector<base>::const_iterator begin() const
	{
		return m_v.begin();
	}
	std::vector<base>::const_iterator end() const
	{
		return m_v.end();
	}
	void add(base b)
	{
		m_v.push_back(b);
	}
	std::string str() const
	{
		std::stringstream ss;
		for(std::vector<base>::const_iterator it=m_v.begin(); it!=m_v.end(); ++it)
			ss<<it->str()<<" ";

		return ss.str();
	}
};

int main()
{
	{
		baseGroup bg;
		for(int i=0; i<10; ++i) bg.add(base(i));
		
		std::cout<<bg.str()<<std::endl;
		
		for(std::vector<base>::const_iterator it=bg.begin(); it!=bg.end(); ++it)
			std::cout<<it->str()<<" ";
		std::cout<<std::endl;
	}
	{
		std::vector<int> v;
		for(int i=0; i<10; ++i) v.push_back(i);
		int i=0;
		for(std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
			assert(it.operator*()==i++);
	}
	{
		std::vector<int> v;
		for(int i=0; i<10; ++i) v.push_back(i);
		std::vector<int>::iterator it=v.end()-1;
		assert(*it==9);
	}
	{
		typedef typename std::vector<int> vector;
		
		vector v;
		for(int i=0; i<10; ++i) v.push_back(i);
		
		vector::iterator it0=v.begin();
		assert(*it0==0);
		vector::iterator it1=it0;
		++it1;
		assert(*it0==0);
		assert(*it1==1);
	}
}
