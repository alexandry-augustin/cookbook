#include <iostream>
#include "Main.h"
#include "BaseTask.h"
#include "Poco/TaskManager.h"

/*virtual*/ void Main::initialize(Application& self)
{
	logger().information("[Main::initialize]");
	
	loadConfiguration();
	ServerApplication::initialize(self);
}

/*virtual*/ void Main::uninitialize()
{
	logger().information("[Main::uninitialize]");
	ServerApplication::uninitialize();
}

/*virtual*/ int Main::main(const std::vector<std::string>& args)
{
	logger().information("[Main::main]");
	
	Poco::TaskManager tm;
	tm.start(new BaseTask);
	waitForTerminationRequest();
	tm.cancelAll();
	tm.joinAll();
	
	return Poco::Util::Application::EXIT_OK;
}

POCO_SERVER_MAIN(Main)