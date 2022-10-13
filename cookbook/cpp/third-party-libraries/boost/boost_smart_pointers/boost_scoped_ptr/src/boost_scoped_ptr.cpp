#include <cassert>
#include <iostream>
#include <boost/scoped_ptr.hpp>
//---------------------------------------------------------
//return smart pointer by value (otherwise ref_count is not incremented)
//---------------------------------------------------------
class base
{
	int 	_n;
public:
	base(int n): _n(n) { }
	~base() { std::cout<<"[base::~base] ["<<_n<<"]"<<std::endl; }
	int get_n() const { return _n; }
	int set_n(int n) { _n=n; }
};
//---------------------------------------------------------
//void f0(boost::scoped_ptr<int> ptr) { }//not allowed by compiler
void f1(const boost::scoped_ptr<int>& ptr) { }
//void f2(boost::scoped_ptr<int> ptr) { }//not allowed by compiler
//void f3(boost::scoped_ptr<int>* ptr) { }//not allowed by compiler
//---------------------------------------------------------
int main()
{
	{
		boost::scoped_ptr<int> ptr1(new int(5));
		//ptr1.reset(new int(5));

		//boost::scoped_ptr<int> other_ptr=ptr1; //not allowed by compiler
		//boost::scoped_ptr<int> other_ptr(ptr1); //not allowed by compiler
		//boost::scoped_ptr<int> other_ptr(ptr1.get()); //crashes!!! (deleted twice)

		assert(*ptr1==5);
		f1(ptr1);
	}
	
	return 0;
}
