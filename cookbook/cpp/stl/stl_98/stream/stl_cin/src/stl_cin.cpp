#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cassert>

// std::cin base class:   std::istream
// whitespace = all invisible characters
// 	new line:	\n
// 	tab:		\t
// 	blank:		' '
// 	cariage return:	\r
// 	vertical bar:	\v
// by default, >> will discard leading whitespaces

int main()
{
	{
		int n_00;
		int n_01;

		std::cin>>n_00>>n_01; //space or \n
		//or
		//std::cin.operator>>(n_00).operator>>(n_01);

		std::cout<<n_00<<" "<<n_01<<std::endl;
	}
	{
	}
	return 0;
}
