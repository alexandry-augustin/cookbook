#ifndef BASEAPPTEST_H
#define BASEAPPTEST_H

#include <string>
#include <vector>
#include <gimo/BaseApp.h>

class TestApp:
	public BaseApp
	
{
public:
	/*virtual*/ void init(std::vector<std::string> args);

	void handleStartUp(base::event::Event* event);
	void handleShutDown(base::event::Event* event);
	void handlePrint(base::event::Event* event);
};

#endif
