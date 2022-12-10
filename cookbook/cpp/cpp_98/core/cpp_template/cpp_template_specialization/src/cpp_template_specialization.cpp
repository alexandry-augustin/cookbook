#include <iostream>
#include <string>
#include <cassert>

// allow specific implementation when T is of a determined type.

template<typename T>
class base_00
{
	T _n;
public:
	base_00(T n): _n(n) { }
	T f_00() const { return 0; } //return 0 all the time despite <int>
};
//specialization
template<>
int base_00<int>::f_00() const { return _n; }

template<typename T>
class base_01
{
	T _n;
public:
	base_01(T n): _n(n) { }
	T f_00() const { return 0; } //return 0 all the time despite <int>
};
//specialization
template<>
class base_01<int>
{
	int _n;
public:
	base_01(int n): _n(n) { }
	int f_00() const { return _n; }
};

template<typename T>
T f_00(T n)
{
	return -1;
}
//specialization
template<>
int f_00<int>(int n)
{
	return n;
}
template<>
float f_00<float>(float n)
{
	return n;
}

int main()
{
	{
		base_00<short int> b_00(4);
		base_00<int> b_01(5);
		
		assert(b_00.f_00()==0);
		assert(b_01.f_00()==5);
	}
	{
		base_01<short int> b_00(4);
		base_01<int> b_01(5);
		
		assert(b_00.f_00()==0);
		assert(b_01.f_00()==5);
	}
	{
		assert(f_00<int>(5)==5);
		assert(f_00<float>(.5)==.5);
		assert(f_00<double>(.5)!=.5);
	}
} 
