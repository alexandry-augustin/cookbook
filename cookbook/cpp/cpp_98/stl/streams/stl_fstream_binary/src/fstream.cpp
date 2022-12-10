#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

//ofstream	ios::out
//ifstream	ios::in
//fstream	ios::in | ios::out

/*class base_01
{
	int		_n;
	std::string	_str;
public:
	std::ostream& operator<<(std::ostream& os)
	{
		return os;
	}
	std::istream& operator<<(std::istream& is)
	{
		return is;
	}
};*/

struct base_00
{
	int	key;
	char	value;
};

void test_00()
{
	{
		std::ofstream ofs;
		char* buf=new char[127];
		for(int i=0; i<127; ++i) //rem: sizeof(int)=4*sizeof(char)
			buf[i]=((char)i+1);

		ofs.open("data.bin", std::ios::binary | std::ios::trunc); //default std::ios::trunc
		assert(!ofs.fail());
		assert(ofs.is_open());
		ofs.seekp(0, std::ios::beg);
		ofs.write(buf, 127);
		ofs.close();
	}
	{
		std::ifstream ifs;
		std::streampos size;
		char* buf;

		ifs.open("data.bin", std::ios::binary | std::ios::ate);
		assert(!ifs.fail());
		assert(ifs.is_open());
		size=ifs.tellg();
		ifs.seekg(0, std::ios::beg);
		buf=new char[size];
		ifs.read(buf, size);
		ifs.close();

		for(int i=0; i<127; ++i)
			assert((int)buf[i]==(i+1));
	}
}

void test_01() //user define datatype
{
	{
		base_00 b_00;
		b_00.key=5;
		b_00.value='a';
		//base_00* y=new base_00[10];

		std::ofstream ofs("data.bin", std::ios::binary);
		ofs.seekp(0);
		ofs.write((char*)&b_00, sizeof(base_00));
		ofs.close();
	}
	{
		base_00 b_00;
		//base_00* y=new base_00[10];

		std::ifstream ifs("data.bin", std::ios::binary);
		ifs.seekg(0);
		ifs.read((char*)&b_00, sizeof(base_00));
		ifs.close();

		//std::cout<<"["<<b_00.key<<", "<<b_00.value<<"]"<<std::endl;
		assert(b_00.key==5);
	}
}

void test_02() //user define datatype (array)
{
	{
		base_00* a=new base_00[10];
		for(int i=0; i<10; ++i)
		{
			a[i].key=i;
			a[i].value='a';
		}

		std::ofstream ofs("data.bin", std::ios::binary);
		ofs.seekp(0);
		ofs.write((char*)a, sizeof(base_00)*10);
		ofs.close();
	}
	{
		//get all elts
		base_00* a=new base_00[10];

		std::ifstream ifs("data.bin", std::ios::binary);
		ifs.seekg(0);
		ifs.read((char*)a, sizeof(base_00)*10);
		ifs.close();

		for(int i=0; i<10; ++i)
			//std::cout<<"["<<a[i].key<<", "<<a[i].value<<"]"<<std::endl;
			assert(a[i].key==i);
	}
	{
		//get arbitrary elt
		base_00 b_00;
		int i=5; //ith elt in the array

		std::ifstream ifs("data.bin", std::ios::binary);
		ifs.seekg(i*sizeof(base_00));
		ifs.read((char*)&b_00, sizeof(base_00)); //read and increment get pointer by sizeof(base_00)
		assert(b_00.key==5);

		ifs.read((char*)&b_00, sizeof(base_00));
		assert(b_00.key==6);

		ifs.close();
	}
}

void test_03() //user define datatype (vector)
{
	{
	 	//using array
		base_00* a=new base_00[10];
		for(int i=0; i<10; ++i)
		{
			a[i].key=i;
			a[i].value='a';
		}

		std::ofstream ofs("data.bin", std::ios::binary);
		ofs.seekp(0);
		ofs.write((char*)a, sizeof(base_00)*10);
		ofs.close();
	}
	{
	 	//using vector
		std::vector<base_00> v(10);
		for(int i=0; i<10; ++i)
		{
			v[i].key=i;
			v[i].value='a';
		}

		std::ofstream ofs("data.bin", std::ios::binary);
		ofs.seekp(0);
		ofs.write((char*)&v.front(), sizeof(base_00)*10);
		ofs.close();
	}
	{
		//get all elts
		std::vector<base_00> v(10); //at least 10

		std::ifstream ifs("data.bin", std::ios::binary);
		ifs.seekg(0);
		ifs.read((char*)&v.front(), sizeof(base_00)*v.size());
		ifs.close();

		for(int i=0; i<10; ++i)
			//std::cout<<"["<<a[i].key<<", "<<a[i].value<<"]"<<std::endl;
			assert(v[i].key==i);
	}
	{
		base_00 b;

		std::ifstream ifs("data.bin", std::ios::binary);

		ifs.seekg(0);
		ifs.read((char*)&b, sizeof(base_00));
		assert(b.key==0);

		ifs.seekg(5*sizeof(base_00));
		ifs.read((char*)&b, sizeof(base_00));
		assert(b.key==5);
		assert(b.value=='a');

		ifs.close();
	}
	{
		std::vector<base_00> v(10);

		std::ifstream ifs("data.bin", std::ios::binary);

		int i=0;
		for(std::vector<base_00>::iterator it=v.begin(); it!=v.end(); ++it)
		{
			ifs.seekg(i++*sizeof(base_00));
			ifs.read((char*)&(*it), sizeof(base_00));
		}
		ifs.close();

		for(int i=0; i<10; ++i)
			assert(v[i].key==i);
	}
	{
		std::vector<base_00> v;

		std::ifstream ifs("data.bin", std::ios::binary);

		int i=0;
		base_00 buf;
		while(true)
		{
			if(!ifs.good())
			{
				v.pop_back();
				break;
			}
			ifs.seekg(i++*sizeof(base_00));
			ifs.read((char*)&buf, sizeof(base_00));
			v.push_back(buf);
		}
		ifs.close();

		assert(v.size()==10);
		for(int i=0; i<v.size(); ++i)
			assert(v[i].key==i);
	}
}

// setup for test_04()

// helper function to convert a string to a number
template <typename T>
T ToNumber(const std::string& s)
{
	T val;
	std::stringstream ss(s);
	ss>>val;
	return val;
}

// operator << for pair<string,string>
std::ostream& operator<<(std::ostream& strm, const std::pair<std::string,std::string>& rec)
{
	strm << rec.first  << std::endl;
	strm << rec.second << std::endl;
	return strm;
}

// operator << for map<string,string>
std::ostream& operator<<(std::ostream& strm, const std::map<std::string,std::string>& smap)
{
	std::map<std::string,std::string>::const_iterator it;

	strm << smap.size() << std::endl;

	for(it=smap.begin(); it!=smap.end(); ++it)
	{
		strm <<(*it);   // uses operator <<  for pair<string,string>
	}
	return strm;
}

// operator << for map< string, map<string,string> >
std::ostream& operator<<(std::ostream& strm, const std::map<std::string,std::map< std::string,std::string> >& ssmap)
{
	std::map<std::string, std::map<std::string,std::string> >::const_iterator it;

	strm<<ssmap.size()<<std::endl;

	for(it=ssmap.begin(); it!=ssmap.end(); ++it)
	{
		strm<<(*it).first << std::endl;
		strm<<(*it).second;   // uses operator <<  for map<string,string>
	}
	return strm;
}

// operator >> for pair<string,string>
std::istream& operator>>(std::istream& strm, std::pair<std::string,std::string>& rec)
{
	std::getline(strm,rec.first);
	std::getline(strm,rec.second);
	return strm;
}

// operator >> for map<string,string>
std::istream& operator>>(std::istream& strm, std::map<std::string,std::string>& smap)
{
	smap.clear();

	std::string s;
	std::getline(strm,s);
	int n = ToNumber<int>(s);

	for(int i=0; i<n; ++i)
	{
		std::pair<std::string,std::string> spair;
		strm>>spair;   // uses operator >>  for pair<string,string>
		smap.insert(spair);
	}
	return strm;
}

// operator >> for map< string, map<string,string> >
std::istream& operator>>(std::istream& strm, std::map<std::string,std::map< std::string,std::string> >& ssmap)
{
	ssmap.clear();

	std::string s;
	std::getline(strm,s);
	int n = ToNumber<int>(s);

	std::map<std::string,std::string> smap;
	for(int i=0; i<n; ++i)
	{
		std::getline(strm,s);
		strm >> smap;   // uses operator >>  for map<string,string>
		ssmap.insert(std::make_pair(s,smap));
	}
	return strm;
}

void test_04() //associative container
{
	//{
	//	typedef std::multimap<int, char> map_t;
	//	map_t map;
	//	map.insert(map_t::value_type(0, 'a'));
	//	map.insert(map_t::value_type(1, 'b'));

	//	std::ofstream ofs("data.bin", std::ios::binary);
	//	ofs.seekp(0);

	//	for(map_t::const_iterator it=map.begin(); it!=map.end(); ++it)
	//		ofs.write((char*)map, sizeof(map_t::value_type)*map.size());

	//	ofs.close();
	//}
	{
		std::map<std::string,std::map< std::string,std::string> > ssmap1;
		std::map<std::string,std::string> smap;

		smap.insert(std::make_pair(std::string("a"), std::string("1")));
		smap.insert(std::make_pair(std::string("b"), std::string("2")));

		ssmap1.insert(std::make_pair(std::string("a"), smap));

		smap.insert(std::make_pair(std::string("c"), std::string("3 - three")));
		ssmap1.insert(std::make_pair(std::string("b"), smap));

		// write to file
		std::ofstream out("data.bin");
		out << ssmap1;
		out.close();

		// read back in, compare with original
		std::map<std::string,std::map< std::string,std::string> > ssmap2;
		std::ifstream in("data.bin");

		in>>ssmap2;
		assert(ssmap1==ssmap2);
	}
}

int main()
{
	test_00();
	test_01();
	test_02();
	test_03();
	test_04();

	return 0;
}
