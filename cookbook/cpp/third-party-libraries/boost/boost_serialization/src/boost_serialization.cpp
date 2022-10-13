#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include <boost/serialization/list.hpp>
#include <boost/archive/text_iarchive.hpp> 
#include <boost/archive/text_oarchive.hpp> 
//---------------------------------------------------------
//std::stringstream ss; 
//
//void save() 
//{ 
//	  boost::archive::text_oarchive oa(ss); 
//	    int i = 1; 
//	      oa << i; 
//} 
//
//void load() 
//{ 
//	  boost::archive::text_iarchive ia(ss); 
//	    int i = 0; 
//	      ia >> i; 
//	        std::cout << i << std::endl; 
//} 
int main(int argc, char* argv[])
{
	//boost::archive::archive_exception e;

	//load();
	//save();
	{
		std::ostringstream oss;
		boost::archive::text_oarchive oa(oss); //serialization as text stream
		int n=1; 

		oa<<n; 
		assert(oss.str()=="22 serialization::archive 9 1");
	}
	{ 
		std::istringstream iss;
		boost::archive::text_iarchive ia(iss); 
		int n=0; 

		ia>>n;
		std::cout << n << std::endl; 
	} 
	return 0;
}
