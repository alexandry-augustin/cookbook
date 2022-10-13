#include <Python.h> //sudo apt-get install python-dev
#include <iostream>
#include <cassert>
#include <boost/python.hpp>
//---------------------------------------------------------
int main()
{
	Py_Initialize();
	{
		boost::python::object main_module=boost::python::import("__main__");
		boost::python::object main_namespace=main_module.attr("__dict__");

		boost::python::exec("print('Hello, world')", main_namespace);
	}
	{
		boost::python::object main_module=boost::python::import("__main__");
		boost::python::object main_namespace=main_module.attr("__dict__");

		boost::python::exec("import random", main_namespace);
		boost::python::object rand=boost::python::eval("random.random()", main_namespace);
		std::cout<<boost::python::extract<double>(rand)<<std::endl;
	}
	{
		boost::python::object main_module=boost::python::import("__main__");
		boost::python::object main_namespace=main_module.attr("__dict__");

		boost::python::object rand_mod=boost::python::import("random");
		boost::python::object rand_func=rand_mod.attr("random");
		boost::python::object rand=rand_func();
		std::cout<<boost::python::extract<double>(rand)<<std::endl;
	}
	{
		boost::python::object main_module=boost::python::import("__main__");
		boost::python::object main_namespace=main_module.attr("__dict__");

	//	boost::python::object rand_mod=boost::python::import("base");
	//	boost::python::object rand_func=rand_mod.attr("f");
	//	boost::python::object rand=rand_func(8, 9);
	}
	{
		try
		{
			boost::python::object rand_mod=boost::python::import("fake_module");
		}
		catch(const boost::python::error_already_set& e)
		{
			//std::string perror_str=parse_python_exception();
			//std::cout<<"Error in Python: "<<perror_str<<std::endl;
		}
	}
	Py_Finalize();
	return 0;
}
