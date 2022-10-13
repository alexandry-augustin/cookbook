#include <iostream>
#include <sstream>
#include <vector>
#include "Poco/AutoPtr.h"
#include "Main.h"

/*virtual*/ void Main::initialize(Poco::Util::Application& self)
{
	logger().information("[Main::initialize]");
	
	loadConfiguration("config/default.ini");
	Poco::Util::Application::initialize(self);
	// add your own initialization code here
}

/*virtual*/ void Main::uninitialize()
{
	logger().information("[Main::uninitialize]");
	
	// add your own uninitialization code here
	Poco::Util::Application::uninitialize();
}

void Main::defineOptions(Poco::Util::OptionSet& options)
{
	logger().information("[Main::defineOptions]");
}

/*virtual*/ void Main::reinitialize(Poco::Util::Application& self)
{
	logger().information("[Main::reinitialize]");
	
	Poco::Util::Application::reinitialize(self);
	// add your own reinitialization code here
}

int Main::main(const std::vector<std::string>& args)
{
	logger().information("[Main::main]");
	
	std::stringstream ss;
	for(std::vector<std::string>::const_iterator it=args.begin(); it!=args.end(); ++it)
		ss<<*it<<" ";
	std::cout<<ss.str()<<std::endl;
	
	std::string str=config().getString("MyApplication.somePath");
	logger().information(str);
	int n=config().getInt("MyApplication.someValue");
	std::cout<<n<<std::endl;
//	logger().information(n);
	
	return Poco::Util::Application::EXIT_OK;
}

POCO_APP_MAIN(Main)