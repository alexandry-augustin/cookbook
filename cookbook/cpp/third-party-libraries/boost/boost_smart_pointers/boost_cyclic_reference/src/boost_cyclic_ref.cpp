#include <iostream>
#include <cassert>
#include <boost/shared_ptr.hpp>
//---------------------------------------------------------
struct base_01;
//---------------------------------------------------------
struct base_00
{
	boost::shared_ptr<base_01> ptr;
	base_00()
	{
		std::cout<<"base_00::base_00"<<std::endl;
	}
	~base_00()
	{
		std::cout<<"base_00::~base_00"<<std::endl;
	}
};
//---------------------------------------------------------
struct base_01
{
	boost::shared_ptr<base_00> ptr;
	base_01()
	{
		std::cout<<"base_01::base_01"<<std::endl;
	}
	~base_01()
	{
		std::cout<<"base_01::~base_01"<<std::endl;
	}
};
//---------------------------------------------------------
int main()
{
	{
		boost::shared_ptr<base_00> b_00(new base_00);
		boost::shared_ptr<base_01> b_01(new base_01);

		b_00->ptr=b_01;
		b_01->ptr=b_00;
	}
	return 0;
}
