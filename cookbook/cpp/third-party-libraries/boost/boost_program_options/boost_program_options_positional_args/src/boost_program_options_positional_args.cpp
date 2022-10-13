#include <cassert>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/version.hpp>
//----------------------------------------------------------
int main(int argc, char* argv[])
{
	{
		namespace po = boost::program_options;

		po::options_description desc("Options");

		unsigned foo;
		desc.add_options()
			("help,h", "produce help message")
			("foo", po::value(&foo), "set foo") 
			;

		po::variables_map vm;
		try
		{
			const po::positional_options_description p; // note empty positional options
			po::store(
				po::command_line_parser( argc, argv).
				options( desc ).
				positional( p ).
				run(),
				vm
			 );
			po::notify( vm );

			if ( vm.count("help") )
			{
				std::cout << desc << "\n";
				std::cout << "boost version: " << BOOST_LIB_VERSION << std::endl;
			}
		}
		catch(const boost::program_options::error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
