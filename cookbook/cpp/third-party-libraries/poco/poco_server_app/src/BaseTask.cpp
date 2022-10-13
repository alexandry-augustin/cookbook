#include "BaseTask.h"
#include "Poco/Util/Application.h"
#include "Poco/DateTimeFormatter.h"

BaseTask::BaseTask():
	Task("BaseTask")
{
}

void BaseTask::runTask()
{
	Poco::Util::Application& app=Poco::Util::Application::instance();
	
	while(!sleep(5000))
	{
		Poco::Util::Application::instance().logger().information("busy doing nothing... "+Poco::DateTimeFormatter::format(app.uptime()));
	}
}