#include <iostream>
using namespace std;

/*class B;

class A
{
public:
	A(){};
	friend void global(A &a);
	friend void B::member(A &a);
private:
	int x;
};

class B
{
public:
	B(){};
	void member(A &a){a.x=10;}
};

void global(A &a)
{
	a.x=5;
}*/


class X
{
protected:
	int m;
};

class a
{
	friend class X;
};

class b
{
};

template<typename T>
class t
{
	T m_n;

	template<typename T>
	friend T fct(const t<T>& u);

public:
	t(int n): m_n(n) { }
};
template<typename T>
T fct(const t<T>& u) { return u.m_n; }

void main()
{
	/*A a;
	global(a);

	B b;
	b.member(a);*/

	/*b _b;
	_b.m;*/

	t<int> u(5);
	cout<<fct(u)<<endl;
}
