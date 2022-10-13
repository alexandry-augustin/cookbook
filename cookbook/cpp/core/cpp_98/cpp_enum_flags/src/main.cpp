//http://www.codeproject.com/Articles/13740/The-Beginner-s-Guide-to-Using-Enum-Flags
//http://weblogs.asp.net/wim/archive/2004/04/07/109095.aspx

#include <iostream>
#include <string>
#include <sstream>

class base
{
public:
	enum my_enum
	{ 
		A=1,
		B=2,
		C=4
		//...
		//2^n
	};

private:	
	my_enum m_e;

public:
	base(my_enum e): m_e(e)
	{
	}

	bool contains(base::my_enum e)
	{
		return (m_e&e)==e;
	}
/*	bool contains(base::my_enum e1, base::my_enum e2)
	{
		return (m_e&(e1|e2))==(e1|e2);
	}*/
	static int sum(int value)
	{
		int sum=0;
		if((value&base::A)==base::A)
			sum+=base::A;
		if((value&base::B)==base::B)
			sum+=base::B;
		if((value&base::C)==base::C)
			sum+=base::C;
		
		return sum;
	}
	static std::string str(int value)
	{
		std::stringstream ss;
		if((value&base::A)==base::A)
			ss<<"[base::A] ";
		if((value&base::B)==base::B)
			ss<<"[base::B] ";
		if((value&base::C)==base::C)
			ss<<"[base::C] ";
		
		return ss.str();
	}
};

bool contains(int value, base::my_enum e)
{
	return (value&e)==e;
}

bool contains(int value, base::my_enum e1, base::my_enum e2)
{
	return (value&(e1|e2))==(e1|e2);
}

int main(int argc, char* argv[])
{
	std::cout<<contains(base::A|base::B, base::A)<<std::endl;
	std::cout<<contains(base::A|base::B, base::B)<<std::endl;
	std::cout<<contains(base::A|base::B, base::C)<<std::endl;

	std::cout<<contains(base::A|base::B, base::A, base::B)<<std::endl;
	std::cout<<contains(base::A|base::B, base::A, base::C)<<std::endl;

	std::cout<<"contains="<<base::str(base::B)<<std::endl;
	std::cout<<"contains="<<base::str(base::A|base::B)<<std::endl;
	std::cout<<"contains="<<base::str(base::A|base::B|base::C)<<std::endl;

	std::cout<<"sum="<<base::sum(base::B)<<std::endl;
	std::cout<<"sum="<<base::sum(base::A|base::B)<<std::endl;
	std::cout<<"sum="<<base::sum(base::A|base::B|base::C)<<std::endl;
	
	base b(base::B);
	std::cout<<b.contains(base::B)<<std::endl;
	
/*	base02(base::A|base::B);
	std::cout<<b.contains(base::A|base::B)<<std::endl;*/
}
