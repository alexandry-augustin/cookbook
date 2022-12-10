#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdint.h>

class base_00
{
	int _n;
public:
	base_00(int n): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};

std::istream& operator>>(std::istream& is, uint8_t& n)
{
	unsigned int temp;
	is>>temp;
	if(temp>255)
		is.setstate(std::ios::failbit);
	else
		n=temp;
	return is;
}

std::ostream& operator<<(std::ostream& os, const base_00& b)
{
	return os<<b.get();
}

std::istream& operator>>(std::istream& is, base_00& b)
{
	int n;
	is>>n;
	b.set(n);
	return is;
}

void f_00(std::iostream& ios)
{
}

void type_conversion_test()
{
	{
		std::stringstream ss;
		int n;
		//float n=0;

		ss<<int(5);
		ss>>n;
		assert(n==5);
	}
	{
		std::stringstream ss;
		int n;

		ss<<float(5.9);
		ss>>n;
		assert(n==5);
	}
}

void misc_test()
{
	{
		std::stringstream ss("abcd");

		ss<<"12";
		assert(ss.str()=="12cd");
	}
	{
		std::stringstream ss("abc");
		//or
		ss.str("abc");

		assert(ss.str()=="abc");
		assert(ss.str()=="abc");
	}
	{
		std::stringstream ss;
		std::string str_00, str_01;

		ss<<"abc 123";

		ss>>str_00;
		assert(str_00=="abc");

		ss>>str_01;
		assert(str_01=="123");
	}
	{
		std::ostringstream oss("a");
		assert(oss.str()=="a");
	}
	{
		std::ostringstream oss;
		oss<<"abc "<<5;
		assert(oss.str()=="abc 5");
	}
	{
		std::stringstream ss;
		base_00 b_00(5);
		int n;

		ss<<b_00;
		assert(ss.str()=="5");
		ss>>n;
		assert(n==5);
		assert(ss.str()=="5");
	}
	{
		std::stringstream ss(std::ios::in|std::ios::out);
		double n;

		ss.str("abc 74.79 .");
		ss.seekg(-7, std::ios::end);
		ss>>n;
		n=n*n;
		ss.seekp(-7, std::ios::end);
		ss<<n;

		assert(ss.str()=="abc 5593.54");
	}
}

void misc_test_01()
{
	{
		//std::string str("0	abc	def	");
		//or
		std::string str("0\tabc\tdef\t");
		std::istringstream iss(str);
		std::ostringstream oss;
		std::string buf;		

		//http://stackoverflow.com/questions/14615671/whats-the-real-reason-to-not-use-the-eof-bit-as-our-stream-extraction-condition
		while(!iss.eof())
		{
			iss>>buf;
			oss<<buf<<", ";
		}

		assert(oss.str()=="0, abc, def, def, ");
	}
	{
		std::string str("0\tabc\tdef\t");
		std::istringstream iss(str);
		std::ostringstream oss;
		std::string buf;		

		while(std::getline(iss, buf, '\t'))
			oss<<buf<<", ";
		oss.seekp(-2, std::ios_base::end);

		assert(oss.str()=="0, abc, def, ");
		assert(oss.str().substr(0, oss.tellp())=="0, abc, def");
	}
	{
		//http://stackoverflow.com/questions/5757721/use-getline-and-while-loop-to-split-a-string
		std::string str("abc	def	");
		char sep='\t';
		std::istringstream iss(str);
		std::vector<std::string> tokens;

		//for(std::string item; std::getline(iss, item, sep); tokens.push_back(item));
		//or
		std::string item;
		while(std::getline(iss, item, sep))
			tokens.push_back(item);
		
		assert(tokens.size()==2);
		assert(tokens[0]=="abc");
		assert(tokens[1]=="def");
	}
}

int main()
{
	misc_test();
	misc_test_01();
	type_conversion_test();
	{
		//[failbit, eofbit, badbit] goodbit
		std::stringstream ss;

		assert(ss.rdstate()==0);

		ss.setstate(std::ios_base::badbit);//2^0
		assert(ss.rdstate()==1);

		ss.setstate(std::ios_base::eofbit);//2^1
		assert(ss.rdstate()==3);

		ss.setstate(std::ios_base::failbit);//2^2
		assert(ss.rdstate()==7);

		ss.setstate(std::ios_base::goodbit);//0
		assert(ss.rdstate()==7);
	}
	{
		std::ostringstream oss;

		oss.setstate(std::ios::failbit);
		assert(oss.fail());
		assert(!oss.good());
	}
	{
		std::istringstream iss("-10");
		int n;

		iss>>n;
		assert(n==-10);
	}
	{
		std::stringstream ss;
		std::string str;

		ss<<"abc";
		ss>>str;
		assert(ss.eof()); //need to be reset manually: clear()
		assert(str=="abc");

		ss<<"123";
		ss>>str;
		assert(str=="abc");
	}
	{
		std::stringstream ss;
		std::string str;

		ss<<"abc";
		ss>>str;
		assert(ss.eof());
		assert(str=="abc");

		ss.clear(); //reset error flags

		ss<<"123";
		ss>>str;
		assert(str=="123");
	}
	{
		//stream size:
		// same using put pointer

		std::istringstream iss("abc\n");
		iss.seekg(0, std::ios::end);
		int size=iss.tellg();
		assert(size==4);
	}
	{
		//extractor test

		std::istringstream iss("123 abc");
		int n;
		std::string str;

		assert(iss.tellg()==0);

		iss>>n;
		assert(iss.good());
		assert(iss.tellg()==3);
		assert(n==123);

		iss>>str;
		assert(iss.eof());
		assert(!iss.good());
		assert(iss.tellg()==-1);
		assert(str=="abc");
	}
	{
		//extractor test

		std::string str("1 2a\n");
		std::istringstream iss(str);
		int n;
		char c;

		assert(iss.tellg()==0);

		iss>>n;
		assert(iss.good());
		assert(iss.tellg()==1);
		assert(n==1);

		iss>>n;
		assert(iss.good());
		assert(iss.tellg()==3);
		assert(n==2);
	
		iss>>c;
		assert(iss.good());
		assert(iss.tellg()==4);
		assert(c=='a');

		//iss>>c;
		//assert(iss.eof());
		//assert(!iss.good());
		//assert(!iss.bad());
		//assert(iss.fail());
		//assert(c=='\n');
	}
	{
		//extractor test

		std::istringstream iss("");
		int n=5;

		assert(iss.good());

		iss>>n;
		assert(iss.fail());
		assert(iss.eof());
		assert(!iss.good());
		assert(n==5);
	}
	{
		//extractor test

		std::istringstream iss("abc def");
		int n=5;

		assert(iss.good());

		iss>>n;
		assert(iss.fail());
		assert(!iss.eof());
		assert(!iss.good());
		assert(n==0);
	}
	{
		//getline():
		// delimiter is excluded

		std::string str("1 2a\n");
		std::istringstream iss(str);
		char a[255];

		iss.getline(a, 255);
		assert(iss.str()==std::string(a)+'\n');

		iss.seekg(0, std::ios::beg); //reset get pointer

		iss.getline(a, 255, ' ');
		assert(iss.str()==std::string(a)+" 2a\n");
	}
	{
		std::stringstream ss;
		f_00(ss);
	}
	{
		std::istringstream iss("abc");
		std::ostringstream oss;

		oss<<iss;

		//std::cout<<oss.str()<<std::endl;
		assert(oss.str()!="abc");
	}
	{
		std::istringstream iss("123 abc 987");
		std::string temp;

		iss>>temp;

		assert(iss.str()=="123 abc 987");
		assert(iss.tellg()==3);
		assert(iss.str().substr(iss.tellg(), iss.str().size()-iss.tellg())==" abc 987");
		assert(iss.str().substr(iss.tellg())==" abc 987");
	}
	{
		std::ostringstream oss;

		uint8_t n=35;
		oss<<n;

		assert(oss.str()=="#");
	}
	{
		std::stringstream ss;

		uint8_t n_00=35;
		ss<<(unsigned int)n_00;
		assert(ss.str()=="35");

		unsigned int n_01;
		ss>>n_01;
		assert(n_01==35);

		uint8_t n_02=n_01;
		assert(n_02==35);
	}
	{
		std::stringstream ss;

		uint8_t n_00=35;
		ss<<(unsigned int)n_00;
		assert(ss.str()=="35");

		uint8_t n_01;
//unsigned int m=n_01;
//ss>>m;
//std::cout<<m<<std::endl;
		//ss>>static_cast<unsigned int>(n_01);
		//assert(n_01==35);
	}
	{
		std::istringstream iss("abc\n \n\n");
		std::string str;

		std::getline(iss, str);
		assert(str=="abc");
		assert(iss.gcount()==0);

		std::getline(iss, str);
		assert(str==" ");
		assert(iss.gcount()==0);

		std::getline(iss, str);
		assert(str.empty());
		assert(iss.gcount()==0);
	}
	{
		std::istringstream iss("abc\n \n\n");
		char a[255];

		iss.getline(a, sizeof(a));
		assert(std::string(a)=="abc");
		assert(iss.gcount()==4); // abc\n

		iss.getline(a, sizeof(a));
		assert(std::string(a)==" ");
		assert(iss.gcount()==2); // ' '\n

		iss.getline(a, sizeof(a));
		assert(std::string(a).empty());
		assert(iss.gcount()==1); // \n
		assert(!iss.eof());

		iss.getline(a, sizeof(a));
		assert(std::string(a).empty());
		assert(iss.gcount()==0);
		assert(iss.eof());
	}
	{
		std::istringstream iss("abc");
		char a[255];

		iss.getline(a, sizeof(a));
		assert(std::string(a)=="abc");
		assert(iss.gcount()==3);
		assert(iss.eof());
	}
	{
		std::istringstream iss("a\n");
		char c;

		assert(iss.tellg()==0);

		c=iss.get();
		assert(c=='a');
		assert(iss.tellg()==1);

		c=iss.get();
		assert(c=='\n');
		assert(iss.tellg()==2);
	}
	{
		std::istringstream iss("abc\n123\n");
		std::string str;

		assert(iss.tellg()==0);

		std::getline(iss, str);
		assert(str=="abc");
		assert(iss.tellg()==4); //point on '1'

		std::getline(iss, str);
		assert(str=="123");
		assert(iss.tellg()==8);

		assert(!iss.eof());
	}
	{
		std::istringstream iss("20140312.1402");
		char buf[4];
		uint32_t year;
		uint8_t month, day, hour, min;

		iss.read(buf, 4);
		assert(iss.tellg()==4);
		assert(buf[0]=='2');
		assert(buf[1]=='0');
		assert(buf[2]=='1');
		assert(buf[3]=='4');
		//assert(year==2014);

		iss.read(buf, 2);
		assert(iss.tellg()==6);
		assert(buf[0]=='0');
		assert(buf[1]=='3');
		assert(buf[2]=='1');
		assert(buf[3]=='4');
		//std::cout<<year<<'\n';

		iss.read(buf, 2);
		assert(iss.tellg()==8);
		assert(buf[0]=='1');
		assert(buf[1]=='2');

		iss.seekg(1+iss.tellg());
		iss.read(buf, 2);
		assert(iss.tellg()==11);
		assert(buf[0]=='1');
		assert(buf[1]=='4');

		iss.read(buf, 2);
		assert(iss.tellg()==13);
		assert(buf[0]=='0');
		assert(buf[1]=='2');
	}
	{
		std::ostringstream oss("abc\n123");

		assert(oss.str()[oss.str().size()-1]=='3');
	}
	{
		std::ostringstream oss("123");

		oss.seekp(-2, std::ios_base::end);
		oss<<9;
		assert(oss.str()=="193");
	}
}
