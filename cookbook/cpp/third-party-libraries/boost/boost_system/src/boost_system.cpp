#include <iostream>
#include <sstream>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
//---------------------------------------------------------
int main()
{
	{
		//boost::system::error_code ec=boost::system::errc::success;
		//boost::system::system_error(ec)
		try
		{
			throw boost::system::system_error(boost::system::error_code());
		}
		catch(const boost::system::system_error& e)
		{
			assert(std::string(e.what())=="Success");

			boost::system::error_code ec=e.code();
			std::stringstream ss;
			ss<<ec;
			assert(ss.str()=="system:0");
			assert(ec.value()==0); //cf man errno
			assert(std::string(ec.message())=="Success");

			assert(ec==boost::system::errc::success);
			switch(ec.value())
			{
			case boost::system::errc::success:
				break;
			}
		}
	}
	return 0;
}
