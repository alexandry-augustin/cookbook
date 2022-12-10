#include <cassert>
#include <cstdlib> //abort
#include <iostream>
#include <exception> //std::terminate, std::exception

/*
std::terminate:
calls the current terminate handler.
By default, the terminate handler calls abort().
But this behavior can be redefined by calling set_terminate.

automatically called when no catch handler can be found for a thrown exception, or for some other exceptional circumstance that makes impossible to continue the exception handling process.

provided so that the terminate handler can be explicitly called by a program that needs to abnormally terminate, and works even if set_terminate has not been used to set a custom terminate handler (calling abort in this case).

never throws exceptions(No-throw guarantee)
*/

void myterminate()
{
	std::cerr<<"entering myterminate\n";
	abort();  // forces abnormal termination
	std::cerr<<"exiting myterminate\n";
}

struct base
{
	base()
	{
		std::cout<<"base::base\n";
	}
	~base()
	{
		std::cout<<"base::~base\n";
		throw std::exception();
	}
};

void f(base b)
{
	std::cout<<"entering f"<<std::endl;
	base b_;
	std::cout<<"exiting f"<<std::endl;
}

void g()
{
	std::cout<<"entering f"<<std::endl;
	base b_00;
	base b_01;
	std::cout<<"exiting f"<<std::endl;
}

int main()
{
	{
/*		std::cout<<"entering main"<<std::endl;
		std::set_terminate(abort); //by default
		//std::set_terminate(myterminate);
		try
		{
			throw std::exception();
		}
		catch(std::exception& e)
		{
			std::terminate();
		}
		std::cout<<"exiting main"<<std::endl;*/
	}
	{
		std::cout<<"entering main"<<std::endl;
		//std::set_terminate(myterminate);
		try
		{
			/*base b;
			f(b);*/
			//or
			g();
		}
		catch(const std::exception& e)
		{
			assert(false); //never reached
		}
		std::cout<<"exiting main"<<std::endl; //never reached
	}
	return 0;
}
