#include <cassert>
#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
//---------------------------------------------------------
class base
{
	int _n;
public:
	base(int n=0): _n(n) { }
	int get_n() const { return _n; }
	void set_n(int n) { _n=n; }
};
//---------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const base& b)
{ 
	return os<<b.get_n();
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		base b(8);

		assert(boost::lexical_cast<int>(b)==8);
		assert(boost::lexical_cast<std::string>(b)=="8");
	}
	return 0;
}
