#include <iostream>
#include <boost/version.hpp>

int main()
{
	{
        // https://www.boost.org/doc/libs/1_44_0/libs/config/doc/html/boost_config/boost_macro_reference.html#boost_config.boost_macro_reference.boost_informational_macros
        // Describes the boost version number in XYYYZZ
        int major_version = (BOOST_VERSION / 100000);
        int minor_version = ((BOOST_VERSION / 100) % 1000);
        int sub_minor_version = (BOOST_VERSION % 100);

        // std::cout << BOOST_VERSION << std::endl;
        std::cout << "version: " << major_version << "." << minor_version << "." << sub_minor_version << std::endl;
	}
	
	return 0;
}
