#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>

// >> extractor operator (works with formatted data: skip white spaces, tabs, newlines)
// << 

class base
{
	int _n;
public:
	base(int n=0): _n(n) { }
	int get_n() const { return _n; }
	void set_n(int n) { _n=n; }
};

//overloading << and >> can't be done as a member function, because the implicit 'this' parameter is the left hand side of the <<-operator.
//Hence, you would need to add it as a member function to the ostream-class. Not good

//As described by Herb Sutter and Scott Meyers, prefer non-friend non-member functions to member functions, 
//to help increase encapsulation. (only getter and setter used)
std::ostream& operator<<(std::ostream& os, const base& b)
{
	return os<<b.get_n();
}

std::istream& operator>>(std::istream& is, base& b)
{
	int n;
	is>>n;
	b.set_n(n);
	return is;
}

int main()
{
	{
//		std::getline(str);
	}
	{
/*		std::string str;
		std::cin>>str; //doesn't support white spaces
		std::cout<<str<<std::endl;*/
	}
	{
/*		char buf[20];
		std::cin.getline(buf, 20);
		std::cout<<std::cin.gcount()<<" char read."<<std::endl;
		for(int i=0; i<20; ++i)	std::cout<<buf[i];*/
	}
	{
//		std::string str;
//		char buf[5];
//		std::istream iss(str);
	}
	{
/*		char buf[5];
		for(int i=0; i<5; ++i)	buf[i]=' ';
		std::cin>>std::setw(5)>>buf;
		for(int i=0; i<5; ++i)	std::cout<<buf[i];
		std::cout<<std::endl;*/
	}
	{
/*		//std::cin.get() does not read new lines
		char c;
		//"test1 test2" => "test1test2"
		while(std::cin>>c)
			std::cout<<c;
		//"test1 test2" => "test1 test2"
		while(std::cin.get(c))
			std::cout<<c;
		
		char buf[5];
		int max_size=5;
		std::cin.get(buf, max_size); //buf[4]=/0
		std::cout<<buf<<std::endl;*/
	}
	{
		base b(6);
		std::stringstream ss;
		ss<<b;
		assert(ss.str()=="6");
//		b>>9;
	}
	{
		//http://codereview.stackexchange.com/questions/6094/a-version-of-operator-that-returns-ostringstream-instead-of-ostream

		base b(6);
		std::ostringstream oss;
		std::string str;

		//oss.operator<<((base)b); //nok: not a member of std::ostream
		operator<<(oss, b);
		assert(oss.str()=="6");

		oss.str("");
		oss<<(operator<<(oss, b).rdbuf());
		assert(oss.str()=="6");

		std::istream(operator<<(oss, b).rdbuf());
		//std::stringstream(operator<<(oss, b));
	}
	return 0;
}
