#include <iostream>
#include <string>
#include <sstream>

class base
{
protected:
	int m_a, m_b;
public:
	base(int a=0, int b=0); //defaults values in declaration, not implementation
	std::string str() const;
};

base::base(int a, int b): m_a(a), m_b(b) { } //initialisation list in implementation, not declaration

std::string base::str() const
{
	std::ostringstream ss;
	ss<<m_a<<" "<<m_b;
	return ss.str();
}

class sub: public base
{
	int m_c;
	public:
	sub()//: m_a(5) //nok
	{
		m_a=5; //ok
	}
};

int main()
{
	{
		base b;
		std::cout<<b.str()<<std::endl;

		sub s;
	}
	return 0;
}
