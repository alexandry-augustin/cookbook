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
		boost::program_options::options_description options_desc;
		boost::program_options::option_description option_desc;

		options_desc.add_options()
			("value,n", "some value")
			;

		//options_desc.add(option_desc);
	}
	{
		boost::program_options::basic_option<char> basic_option;
	}
	{
		boost::program_options::untyped_value	untyped_value;
		boost::program_options::option_description option_description("name",
			&untyped_value, "desc");
	}
	return 0;
}
