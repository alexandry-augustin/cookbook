#include <cassert>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/program_options/detail/config_file.hpp>
//#include <boost/program_options/parsers.hpp>
//----------------------------------------------------------
// bool flags:
// * -b true | -b 1 | -b yes | -b on
// * -b false | -b 0 | -b no | -b off
//Case is ignored.
//----------------------------------------------------------
//TODO discriminate between command-line default value and user explicit assignement
//----------------------------------------------------------
int main(int argc, char* argv[])
{
	/*{
		//./bin/boost_program_options -h

		boost::program_options::options_description options_desc("title");
		options_desc.add_options()
			("help,h", "Display this help message")
			("version,v", "Display the version number");

		boost::program_options::variables_map variables_map;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options_desc),
			variables_map); //throw if unknow option in command line

		assert(variables_map.count("help")>0);
		assert(variables_map.count("h")==0);
	}*/
	/*{
		//./bin/boost_program_options

		int value=9;

		boost::program_options::options_description options_desc("title");
		options_desc.add_options()
			("value,n", boost::program_options::value<int>(&value), "some value")
			;

		boost::program_options::variables_map variables_map;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options_desc),
			variables_map); //throw if unknow option in command line

		assert(value==9);
	}*/
	{
		//./bin/boost_program_options -m 2

		int value_00=0;
		int value_01=0;

		boost::program_options::options_description options_desc("title");
		options_desc.add_options()
			("value_00,n", boost::program_options::value<int>(&value_00)->default_value(value_00), "some value")
			("value_01,m", boost::program_options::value<int>(&value_01)->default_value(value_01), "some value")
			;

		boost::program_options::variables_map variables_map;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options_desc),
			variables_map); //throw if unknow option in command line
		boost::program_options::notify(variables_map); //required to set value_01

		assert(variables_map.count("value_00")>0); //when default value used, count() always > 0 regardless if explicitly in cmd line args
		assert(variables_map["value_00"].defaulted());
		assert(value_00==0);

		assert(variables_map.count("value_01")>0); //when default value used, count() always > 0 regardless if explicitly in cmd line args
		assert(!variables_map["value_01"].defaulted());
		assert(value_01==2);
	}
	//-------------------------------------------------
	//double dashes (POSIX standard)
	//options_description container of option_description
	//-------------------------------------------------
	//add_options:
	// 	returns an object of type options_description_easy_init. 
	// 	operator() overloaded to return a reference to itself (to chain the calls)
	//
	//The difference between chaining the calls and calling add_options several times 
	//is that in the former case a single instance of options_description_easy_init is created 
	//and each time you invoke operator() on it, it adds the options to the owner (options_description). 
	//If you were to call add_options multiple times each call would create a new instance of options_description_easy_init.
	//-------------------------------------------------
	/*{
		std::string status("success");
		boost::program_options::basic_command_line_parser<char>	basic_command_line_parser(argc, argv);
		boost::program_options::option				option;
		std::vector<boost::program_options::option>		options;
		boost::program_options::option_description		option_description;
		boost::program_options::options_description		options_description;
		boost::program_options::untyped_value			untyped_value;
		
		basic_command_line_parser.options(options_description); //required
		try
		{
			basic_command_line_parser=basic_command_line_parser.allow_unregistered();
			boost::program_options::basic_parsed_options<char> basic_parsed_options
				=basic_command_line_parser.run();
			options=basic_parsed_options.options;
			if(!options.empty())
			{
				option=options[0];
				std::cout<<"[key:"<<option.string_key<<"]"<<std::endl;
				std::vector<std::string> value=option.value;
				if(!value.empty())
					std::cout<<"[value:"<<value[0]<<"]"<<std::endl;
			}
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}
	{
		boost::program_options::variables_map variables_map;
		
		std::string name="option_name";
		boost::program_options::variable_value value(std::string("some value"), false);
		variables_map.insert(std::pair<std::string, boost::program_options::variable_value>(name, value));
	}
	{
		std::string status("success");
		boost::program_options::options_description options_desc("base_options");
		try
		{
			boost::program_options::basic_parsed_options<char> options=
				boost::program_options::parse_command_line(argc, argv, options_desc);
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}
	{
		std::string status("success");
		int n;
		boost::program_options::options_description options_desc("base_options");
//std::cout<<options_desc.format_name()<<std::endl;
		options_desc.add_options()
			//no associative value
			("flag,f", "info about flag") //--flag or -f 
			//("flag", "info about flag") //--flag (no associative value)
			//(",f", "info about flag") //-f (no associative value)
			//associative value: -n [value]
		;
		options_desc.add_options()(",n", boost::program_options::value<int>(&n), "info about n");
		//options_desc.add_options()(",n", boost::program_options::value<int>(&n)->required(), "info about n");
		boost::program_options::variables_map variables_map; //derived from std::map<std::string, class variable_value>
		try
		{
			boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options_desc),
				variables_map); //throw if unknow option in command line

			if(!variables_map.count("flag"))
				throw std::exception();

			//the below throws
			//std::cout<<"name="<<var_map["name"].as<std::string>()<<std::endl;
			//std::cout<<"phoneNumber="<<var_map["phoneNumber"].as<int>()<<std::endl;  //uses boost::any_cast

			boost::program_options::notify(variables_map); //throws if required options not there
			std::cout<<options_desc<<std::endl;
			std::cout<<"[size:"<<variables_map.size()<<"]"<<std::endl;
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}
	{
		std::string status("success");
		std::string ip_00, port_00;
		std::string ip_01, port_01;
		boost::program_options::options_description options_desc("base_options");
		options_desc.add_options()
			("server_00.ip", boost::program_options::value<std::string>(&ip_00), "ip address server 00")
			("server_00.port", boost::program_options::value<std::string>(&port_00), "port server 00")
			("server_01.ip", boost::program_options::value<std::string>(&ip_01), "ip address server 01")
			("server_01.port", boost::program_options::value<std::string>(&port_01), "port server 01")
		;
		boost::program_options::variables_map variables_map;
		std::ifstream ifs("base.ini");
		assert(ifs.is_open());
		try
		{
			assert(variables_map.size()==0);
			//will throw on unknow options
			boost::program_options::store(
				boost::program_options::parse_config_file(
				ifs, options_desc), variables_map);
			assert(variables_map.size()>0);
		}
		catch(const std::exception& e)
		{
			status=e.what();
		}
		std::cout<<status<<std::endl;
	}*/
	return 0;
}
