#include <exception>
#include <string>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
void run_00()
{
	throw std::exception();
}
//---------------------------------------------------------
int main()
{
	{
		//try
		//{
			boost::thread thread0(run_00);
		//}
		//catch(const std::exception& e)
		//{
		//}
		//thread0.join();
		while(true);
	}
	return 0;
}
