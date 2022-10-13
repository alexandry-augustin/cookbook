#include <cassert>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/program_options/detail/config_file.hpp>
//#include <boost/program_options/parsers.hpp>
//----------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		std::string status("success");
		std::ifstream ifs("base.ini");
		assert(ifs.is_open());
		std::set<std::string> allowed_options;
		boost::program_options::option	option;
		try
		{
			boost::program_options::detail::config_file_iterator it(ifs, allowed_options, true);
			boost::program_options::detail::config_file_iterator end;
			for(; it!=end; ++it)
			{
				option=*it;
				std::vector<std::string> value(option.value);
				std::cout<<option.string_key<<"="<<value[0]<<std::endl;
			}
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}
/*	{
		std::string status("success");
		std::ifstream ifs("base.ini");
		assert(ifs.is_open());
		std::set<std::string> allowed_options;
		allowed_options.insert("server_00.ip");
		allowed_options.insert("server_00.port");
		allowed_options.insert("server_01.ip");
		allowed_options.insert("server_01.port");
		try
		{
			//iterate over <option> elements
			boost::program_options::detail::config_file_iterator it(ifs, allowed_options, true);
			boost::program_options::detail::config_file_iterator end;
			for(; it!=end; ++it)
			{
				*it; //is of type option
				std::cout<<it->string_key<<"="<<it->value[0]<<std::endl;
			}
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}*/
	return 0;
}
