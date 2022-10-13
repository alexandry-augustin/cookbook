#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>

class base_00
{
	int		_n;
	std::string	_str;
	double		_d;
public:
	base_00(int n=0, double d=0.0, std::string str=""): _n(n), _d(d), _str(str) { }
	void read(std::istream& in)
	{
		in>>_n;
		in.seekg(1+in.tellg()); //skip the extra '\n'
		std::getline(in, _str);
		in>>_d;
	}
	void write(std::ostream& out) const
	{
		out<<_n<<'\n';
		out<<_str<<'\n';
		out<<_d<<'\n';
	}
};

int main()
{
	{
		base_00 b_01(1, 1.1, "number one");
		base_00 b_02(2, 2.2, "number two");
		base_00 b_03(3, 3.3, "number three");

		std::ofstream ofs("data");
		assert(ofs.good());

		b_01.write(ofs);
		b_02.write(ofs);
		b_03.write(ofs);

		ofs.close();
	}
	{
		std::ifstream ifs("data");
		std::list<base_00> l;
		base_00 buf;

		assert(ifs.good());

		//buf.read(ifs);
		//while(!ifs.eof())
		//{
		//	l.push_back(buf);
		//	buf.read(ifs);
		//	//buf.write(std::cout);
		//}

		buf.read(ifs);
		l.push_back(buf);
		buf.read(ifs);
		l.push_back(buf);
		buf.read(ifs);
		l.push_back(buf);

		for(std::list<base_00>::const_iterator it=l.begin(); it!=l.end(); ++it)
			it->write(std::cout);
		std::cout.flush();
		
		ifs.close();
	}
	return 0;
}
