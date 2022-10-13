#include <iostream>
#include <string>
#include <sstream>

class sub;

class base
{
	friend class sub;
	friend std::string to_string(const base& b);

	int m_n;
public:
	base(int n): m_n(n) {}	
};

class sub 
{
	base	m_b;
public:
	sub(int n): m_b(n) {}

	void fct(const base& b)
	{
		std::cout<<b.m_n<<std::endl;
	}
	int get() const
	{
		return m_b.m_n;
	}
};

std::string to_string(const base& b)
{
	std::stringstream ss;
	ss<<b.m_n;
	return ss.str(); 
}

int main()
{
	sub s(1);
	base b(2);
	std::cout<<s.get()<<std::endl;
	s.fct(b);
	std::cout<<to_string(b)<<std::endl;

	return 0;
}
