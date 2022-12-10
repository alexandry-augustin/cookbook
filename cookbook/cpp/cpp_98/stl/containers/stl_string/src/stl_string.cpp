#include <iostream>
#include <cassert>
#include <string>

// std::string.length() == std::string.size()
// As per the documentation (http://en.cppreference.com/w/cpp/string/basic_string), these are just synonyms.  size() is there to be consistent with other STL containers (like vector, map, etc.)
// and length() is to be consistent with most peoples' intuitive notion of character strings.
// People usually talk about a word, sentence or paragraph's length, not its size, so length() is there to make things more readable.

std::string replace_00(const std::string& str)
{
	std::string ret;
	for(std::string::const_iterator it=str.begin(); it!=str.end(); ++it)
	{
		if(*it=='\n')
		{
			ret+="\\n";
			continue;
		}
		ret+=*it;
	}
	return ret;
}

void comparison()
{
	{
		//operator overloading

		//assert("a_"+"b"=="a_b"); //nok
		assert("a_"+std::string("b")=="a_b");
		assert(std::string("a_")+"b"=="a_b");
		assert(std::string("a_")+std::string("b")=="a_b");
		assert(std::string("a_")+std::string("b")==std::string("a_b"));
	}
	{
		// int std::string::compare():
		// str_00.compare(str_01)
		//	0:  str_00==str_01
		//	<0: str_00<str_01
		//	>0: str_00>str_01
	}
	{
		std::string str_00("123\n");
		std::string str_01("123");

		assert(str_00!=str_01);
	}
	{
		//assert("abc">"ab"); //runtime error
		assert(std::string("abc")>"ab");
		assert(std::string("abc")>"ab");
		assert(std::string("abc")>std::string("ab"));
		assert(std::string("abc")>"abb");
		assert(std::string("ab")<"abb");
		assert(std::string("ab")<"abd");
		assert(std::string("ab")>"aa");
		assert(std::string("ab")<"abc");
		assert(std::string("ab")<"abd");
	}
}

void substr()
{
	//string substr(size_t pos=0, size_t len=npos) const;
	{
		std::string str("abc.txt");

		assert(str.substr()==str);
		assert(str.substr(4)=="txt"); //(pos)
		assert(str.substr(2, 3)=="c.t"); //(pos, len)
		assert(str.substr(0, 3)=="abc"); //(pos, len)

		unsigned int pos;
		pos=str.find(".");
		assert(pos==3);
		assert(str.substr(pos)==".txt");
		assert(str.substr(pos+1)=="txt");

		pos=str.find("c.");
		assert(pos==2);
		assert(str.substr(pos)=="c.txt");
	}
}

int main()
{
	comparison();
	substr();
	{
		std::string str("abc");
		assert(str[0]=='a');
		assert(str[1]=='b');
	}
	{
		std::string str("abc");
		str.append("\0"); //will be ignored
		str.append("abc");
		assert(str=="abcabc");
	}
	{
		std::string str("abc");
		str.append("\0 123");
		assert(str=="abc");
	}
	{
		char a[255]="abc\n123\n";
		std::string str(a);

		assert(str.size()==8);
		assert(str.length()==8);
	}
	{
		std::string s;
		std::cout<<"input: ";
		std::cin>>s;
		std::cout<<s+" end"<<std::endl;

		std::string r("test");
		std::string u(r, 2);
		std::cout<<u<<std::endl;
	}
	{
		std::string str("asda\nsdads\ndsad");

		std::cout<<replace_00(str)<<std::endl;

		//std::replace(str.begin(), str.end(), '\n', 'n');
		while(str.find('\n')!=std::string::npos)
			str.replace(str.find("\n"), 1, "\\n");
		std::cout<<str<<std::endl;
	}
	{
		std::string str("abc");

		for(std::string::iterator it=str.begin(); it!=str.end(); ++it);
	}
	return 0;
}
