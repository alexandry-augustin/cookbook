#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Poco/Util/Application.h"

class BaseApp: public Poco::Util::Application
{
public:
	int main(const std::vector<std::string>& args)
	{
		std::stringstream ss;
		for(std::vector<std::string>::const_iterator it=args.begin(); it!=args.end(); ++it)
			ss<<*it<<" ";
		std::cout<<ss.str()<<std::endl;
		
		return Poco::Util::Application::EXIT_OK;
	}
};

POCO_APP_MAIN(BaseApp)