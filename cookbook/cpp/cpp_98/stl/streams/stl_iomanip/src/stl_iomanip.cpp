#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>

void f()
{
	{
		std::ostringstream oss;

		oss<<true;
		assert(oss.str()=="1");

		oss.str("");

		oss<<std::boolalpha<<true;
		assert(oss.str()=="true");
	}
	//{
	//	std::istringstream iss("true");
	//	bool b=false;

	//	iss.setf(std::ios_base::boolalpha, std::ios_base::floatfield);
	//	iss>>b;
	//	assert(b);
	//}
	{
		std::ostringstream oss;

		oss<<std::hex;
		oss<<14;
		assert(oss.str()=="e");
		oss<<13;
		assert(oss.str()=="ed");
		oss<<std::dec;
		oss<<11;
		assert(oss.str()=="ed11");
	}
}

void setw_test()
{
	//setw: minimum width of each insertion (no truncation)
	//default fill: ' '
	//default justification: right
	{
		std::ostringstream oss;

		oss<<std::setw(2);
		oss<<"abc";
		assert(oss.str()=="abc");
	}
	{
		std::ostringstream oss;

		oss<<std::setw(5);
		oss<<std::left;
		oss<<"-abc";
		assert(oss.str()=="-abc ");
	}
	{
		std::ostringstream oss;

		oss<<std::setw(5);
		oss<<std::right;
		oss<<"-abc";
		assert(oss.str()==" -abc");
	}
	{
		std::ostringstream oss;

		oss<<std::setw(5);
		oss<<std::internal;
		oss<<"-123";
		//assert(oss.str()=="- abc");
		//std::cout<<oss.str()<<std::endl;
	}
	{
		//cout.width and std::setw() can't be set permanently
		int n=-77;
		std::cout.width(6); std::cout << std::internal << n << '\n';
		std::cout.width(6); std::cout << std::left << n << '\n';
		std::cout.width(6); std::cout << std::right << n << '\n';
	}
	{
		std::ostringstream oss;

		oss<<std::setw(5);
		oss<<"abc";
		assert(oss.str()=="  abc");

		oss<<std::setw(5);
		oss<<"123";
		assert(oss.str()=="  abc  123");
	}
	{
		std::cout<<std::setw(10);
		std::cout<<'0';
		std::cout<<'0';

		std::cout<<std::endl;

		std::cout<<std::setw(10)<<'0';
		std::cout<<std::setw(10)<<'0';

		std::cout<<std::endl;
	}
	{
//		std::string str;
//		std::cout<<"type \"abc\":";
//		std::cin>>std::setw(2)>>str;
//		assert(str=="ab");
	}
}

void setfill_test()
{
	{
		std::ostringstream oss;

		oss<<std::setw(5)<<std::setfill('.'); //order is irrelevant
		oss<<"abc";
		assert(oss.str()=="..abc");
	}
}

std::ostream& manipulator_00(std::ostream& out)
{
	return out<<'\t';
}

int main()
{
	{
		std::cout<<std::setfill('-')<<std::setw(80)<<"-"<<std::endl;
	}
	{
//		std::cout<<std::resetiosflags(std::ios::showbase);
//		std::ios::fmtflags flags(std::cout.flags());
//		std::cout.flags(flags);
	}
	{
		//custom manipulator
		std::ostringstream oss;
		oss<<"a"<<manipulator_00<<"b";
		assert(oss.str()=="a\tb");
	}
	f();
	setw_test();
	setfill_test();
	{
/*		using namespace std;
		long p = 30000;
		cout<<p
			<<" printed using the default pad character\n"
			<<"for right and left justified and as hex\n"
			<<"with internal justification.\n"
			<<"--------------------------------------------\n";

		cout.setf(ios::showbase);
		cout<<setw(10)<<p<<endl;
		cout.setf(ios::left,ios::adjustfield);
		cout<<setw(10)<<p<<endl;
		cout.setf(ios::internal,ios::adjustfield);
		cout<<setw(10)<<hex<<p<<"\n\n";
		cout<<"Using various padding character"<<endl;
		cout<<"-------------------------------"<<endl;
		cout.setf(ios::right,ios::adjustfield);
		cout.fill('#');
		cout<<setw(10)<<dec<<p<<'\n';
		cout.setf(ios::left,ios::adjustfield);
		cout<<setw(10)<<setfill('$')<<p<<'\n';
		cout.setf(ios::internal,ios::adjustfield);
		cout<<setw(10)<<setfill('*')<<hex<<p<<endl;*/
	}

	return 0;
}
