#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class base
{
	base() {}

	int m_n;
public:
	base(int n): m_n(n) {}

	int get_n() const { return m_n; }
	void set_n(int n) { m_n=n; }

	string str() const 
	{
		stringstream ss;
		ss<<get_n();
		return ss.str();
	}
};

class sub: public base
{
public:
	sub(int n): base(n) { }

	void clear() { set_n(0); }
};

void fct(const base& b) { }

int main()
{
//	base* b=new base(5);
//	sub* s=new sub(5);
//	b=s;
//	cout<<b->str()<<endl;
	
	sub* s;
	base* b=s;
	sub* s_=static_cast<sub*>(b);
	std::cout<<(b==s)<<std::endl; //true
	std::cout<<(s_==s)<<std::endl; //true
	
	return 0;
}
