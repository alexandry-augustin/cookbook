#include <boost/array.hpp>

int main()
{
	{
		boost::array<char, 4> a;
		a.fill(' ');
		a[0];
		a.size();
		a.c_array();
	}
	
	{
		typedef typename boost::array<char, 4>	array;
		
		array a;
		a.fill('.');
		for(array::iterator it=a.begin(); it!=a.end(); ++it)
			assert(*it=='.');
	}
	
	return 0;
}
