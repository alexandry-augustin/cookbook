// property_tree  vs program_options
// http://boost.2283326.n4.nabble.com/Do-really-property-tree-and-program-options-overlap-td2606087.html
//---------------------------------------------------------
// property_tree:
//		hierarchical (DOM: XML, JSON...)
//
// program_options :
//		linear structure (flat: ini).
//		does not support writing back to config files.
//		supports options descriptions and notify mechanisms. 
//
// both:
//		parse command lines options.
//---------------------------------------------------------
#include <iostream>
#include <exception>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
//---------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		try
		{
			boost::property_tree::ptree prop_tree;
			boost::property_tree::ini_parser::read_ini("file.ini", prop_tree);

			std::cout<<prop_tree.get<std::string>("Section1.Value1")<<std::endl;
			std::cout<<prop_tree.get<std::string>("Section1.Value2")<<std::endl;
		}
		catch(std::exception& e)
		{
			std::cout<<"Exception: "<<e.what()<<"."<<std::endl;
			return 1;
		}
	}
	return 0;
}
