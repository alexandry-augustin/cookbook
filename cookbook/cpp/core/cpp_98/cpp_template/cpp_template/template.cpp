#include<iostream>
#include<string>

template <typename T, typename U>
class Container
{
	T value1;
	U value2;
public:
	Container(){}
	void doSomething(T val1, U val2);
};

template<typename T, typename U>
void Container<T, U>::doSomething(T val1, U val2) { }

template <>
class Container<char, string>
{
	char value1;
	string value2;
public:
	Container(){}
	void doSomething(char val1, string val2) { }
};

template<>
inline void Container<char,string>::doSomething(char val1, string val2) { }

//--- Function Template

template <typename T>
T fct(const T &a)
{
	return a;
}

//--- Class Template

template <typename T>
class base
{
	T a;
	void fct(T &a);
};
template <typename T>
void base<T>::fct(T &a)
{
}

//--- Template Specialization

// Allow specific implementation when T is of a determined type.
template<typename T>
class my_pair
{
	T m_a, m_b;
public:
	my_pair(T a, T b): m_a(a), m_b(b) { }
	T mod() const { return 0; } //return 0 all the time despite <int>
};
template<>
int my_pair<int>::mod() const {	return m_a%m_b; }

//--- Class Template + Inheritance



//--- Main

void main()
{
	int a=fct<int>(int(5));
	//or int a=fct(int(5));   //needed if the function's prototype doesn't include T

	base<int> b;

	my_pair<int> n(-1, 2);
	//cout<<n.mod()<<endl;
	my_pair<double> m(1.2, 0.1);
	//cout<<m.mod()<<endl;

} 
