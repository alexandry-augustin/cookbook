#include <cassert>

template <class T>
struct base_00
{
	T t;
};

template <template<typename A> class T>
//or
//template <template<class A> class T>
//or
//template <template<typename> class T> //'A' can be omitted, because there is no way that it can be used
struct base_01
{
	T<int> t;
};

//usage example
//http://www.informit.com/articles/article.aspx?p=376878
template <typename T>
class list
{
};

template <typename T, template <typename> class Cont>
class stack
{
	Cont<T> s;
	void push(const T& t);
};
 
stack<int, list> s_00;

template <template<typename T_00> class T_01, typename T_02>
//or
//template <template<typename> class T_01=base_00, typename T_02> //FIXME
void base_02()
{
};

int main()
{
	{
		base_01<base_00> b_00;

		b_00.t.t=5;
		assert(b_00.t.t==5);
	}
	{
//		base_02<base_00, base_00<int> > b;
	}
	return 0;
}
