#include <iostream>
#include <algorithm>
#include <vector>

class myClass 
{
	int m_n;
public:
	friend std::ostream& operator<<(std::ostream &out, const myClass &c);
	friend bool sortFct(const myClass& i, const myClass& j);

	myClass(int n=0): m_n(n) { }
	myClass(const myClass &c): m_n(c.m_n) { }
	bool operator<(const myClass &c) { return m_n<c.m_n; }
};

bool sortFct(const myClass& i, const myClass& j) { return (i.m_n<j.m_n); }

std::ostream& operator<<(std::ostream &out, const myClass &c)
{
	out<<c.m_n;
	return out;
}

template<typename T>
class myClassTemplate
{
	T m_n;
public:
	template<typename T> friend std::ostream& operator<<(std::ostream &out, const myClassTemplate &c);
	template<typename T> friend bool sortFctTemplate(const myClassTemplate<T>& i, const myClassTemplate<T>& j);

	myClassTemplate(T n=0): m_n(n) { }
	myClassTemplate(const myClass &c): m_n(c.m_n) { }
};

template<typename T>
bool sortFctTemplate(const myClassTemplate<T>& i, const myClassTemplate<T>& j) { return (i.m_n<j.m_n); }

template<typename T>
std::ostream& operator<<(std::ostream &out, const myClassTemplate<T> &c)
{
	out<<c.m_n;
	return out;
}

	template<typename T>
	void print(const T& t, unsigned int size)
	{
		for(unsigned int i=0; i<size; ++i)
			std::cout<<t[i]<<" ";
		std::cout<<std::endl;
	}

int main() 
{
	myClass a[]={5, 0, 7, 1, myClass(4)};
	std::vector<myClass> v(a, a+5);
	
	print(v, v.size());
	//std::sort(v.begin(), v.end()); //need operator< overloaded
	std::sort(v.begin(), v.end(), sortFct); //don't need operator< overloaded
	print(v, v.size());

	myClassTemplate<int> b[]={5, 0, 7, 1, myClassTemplate<int>(4)};
	std::vector<myClassTemplate<int> > w(b, b+5);
	
	print(w, w.size());
	std::sort(w.begin(), w.end(), sortFctTemplate<int>); //don't need operator< overloaded
	print(w, w.size());

	print(a, 5);
	std::sort(a, a+5);
	print(a, 5);

	return 0;
}
