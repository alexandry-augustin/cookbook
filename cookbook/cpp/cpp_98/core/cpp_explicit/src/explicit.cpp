#include <string>
#include <iostream>
#include <string>
#include <sstream>

//disallow compiler to used constuctor parameters to cast the object

class non_explicit_base 
{
	int m_n;
public:
	non_explicit_base(int n): m_n(n)
	{
		std::cout<<"[non_explicit_base::non_explicit_base(int)]"<<std::endl;
	}
	non_explicit_base(const non_explicit_base& b)
	{
		m_n=b.m_n;
		std::cout<<"[non_explicit_base::non_explicit_base(non_explicit_base)]"<<std::endl;
	}
	non_explicit_base(std::string str)
	{
		std::cout<<"[non_explicit_base::non_explicit_base(std::string)]"<<std::endl;
	}

	std::string str() const
	{
		std::stringstream ss;
		ss<<"[non_explicit_base::str] ";
		ss<<m_n;

		return ss.str();
	}
};

class explicit_base 
{
	int m_n;
public:
	explicit explicit_base(int n): m_n(n)
	{
		std::cout<<"[explicit_base::explicit_base(int)]"<<std::endl;
	}
	explicit explicit_base(const explicit_base& b)
	{
		m_n=b.m_n;
		std::cout<<"[explicit_base::explicit_base(explicit_base)]"<<std::endl;
	}
	explicit explicit_base(std::string str)
	{
		std::cout<<"[explicit_base::explicit_base(std::string)]"<<std::endl;
	}

	std::string str() const
	{
		std::stringstream ss;
		ss<<"[explicit_base::str] ";
		ss<<m_n;

		return ss.str();
	}
};

//void f(A) {}

//class myString
//{
//	string m_string;
//public:
//	myString(int n): m_string(n, '0'){  }//initialized m_string by a repetition of character '0' n times
//	void print() const { cout<<m_string<<endl; }
//};
//void print(myString s){ s.print(); }

int main()
{
	non_explicit_base b=5;
	non_explicit_base c=b;
	non_explicit_base d=std::string("test");

	//explicit_base z=5;	//illegal
	explicit_base z(5);
	//explicit_base y=z;	//illegal
	explicit_base y(z);
	//explicit_base x=std::string("test");	//illegal
	explicit_base x(std::string("test"));




//	A a1 = 37;		//illegal if explicit: A a1 = A(37);
//	A a2 = A(47);	//OK
//	A a3(57);		//OK
//	a1 = 67;		//illegal if explicit: a1 = A(67);
//	f(77);			//illegal if explicit: f(A(77));
//	// exemple when to disable it
//	print(3); //"3" expected, but prints an empty string of length 3
	return 0;
}
