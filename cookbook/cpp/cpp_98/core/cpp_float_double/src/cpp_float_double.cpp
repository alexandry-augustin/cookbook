#include <iostream>
#include <cassert>
#include <cmath>	//NAN macro and isnan()
#include <limits>       //std::numeric_limits

//double std::numeric_limits<double>::quiet_NaN()	NaN;//or NAN in math.h

int main()
{
	{
		float f=0.0/0.0;
		float g=NAN; //NAN and INFINITY macros
		float h=std::numeric_limits<float>::quiet_NaN();
		float i=std::numeric_limits<float>::signaling_NaN(); //throws exception
	
		assert(isnan(f));
		assert(isnan(g));
		assert(isnan(h));
		std::cout<<f<<std::endl;
	}
	{
		assert((NAN>10.0)==false);
		assert((NAN<10.0)==false);
		assert((NAN==10.0)==false);
	}
	return 0;
}
