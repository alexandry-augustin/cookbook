#include <iostream>
#include <cassert>
#include <boost/scoped_array.hpp>

//return smart pointer by value (otherwise ref_count is not incremented)

class Base
{
	int 	_n;
public:
	Base(int n):
		_n(n) 
	{
	}
	~Base()
	{
		std::cout<<"[Base::~Base] ["<<_n<<"]"<<std::endl;
	}
	int get_n() const
	{
		return _n;
	}
	int set_n(int n)
	{
		_n=n;
	}
};

int main()
{
	{
		int size=4;
		boost::scoped_array<int> ptr_array(new int[size]);
		for(int i=0; i<size; ++i)
			ptr_array[i]=i;
		for(int i=0; i<size; ++i)
			assert(ptr_array[i]==i);

		//std::cout<<ptr_array.get()<<std::endl;
	}
	//std::cout<<ptr_array.get()<<std::endl;
	
	return 0;
}
