#include "BaseAppTest.h"
#include <cassert>
#include <boost/bind.hpp>
#include <gimo/BaseApplication.h>
#include <gimo/BaseAny.h>
#include <gimo/BaseAnyFactory.h>
#include <gimo/BaseEventFactory.h>

/*virtual*/ void TestApp::init(std::vector<std::string> args)
{
	BaseApp::init(args);
	
	std::cout<<"[TestApp::init] "<<std::endl;
	
	_idle_sleep_time=5;	//[ms]
	_lag_simulation=0;	//[ms]
	
	connectEventHandler("event.print", boost::bind(&TestApp::handlePrint, this, _1));
	connectEventHandler("event.startup", boost::bind(&TestApp::handleStartUp, this, _1));
	connectEventHandler("event.shutdown", boost::bind(&TestApp::handleShutDown, this, _1));
	
	base::event::Event* event=base::event::Factory::get("event.startup");
	postEvent(event);
}

void TestApp::handlePrint(base::event::Event* event)
{
	std::cout<<"[TestApp::handlePrint]"<<std::endl;
	
	assert(event->getArgs()->at(0)->contains<std::string>());
	std::string message=event->getArgs()->at(0)->cast<std::string>();
	
	std::cout<<message<<std::flush;
}

void TestApp::handleStartUp(base::event::Event* event)
{
	std::cout<<"[TestApp::handleStartUp]"<<std::endl;
	
	assert(event->getType()=="event.startup");
	
	base::event::Event* new_event=NULL;
	
	new_event=base::event::Factory::get("event.print");
	new_event->getArgs()->push_back(base::any::Factory::get(std::string("hello ")));
	postEvent(new_event);
	
	new_event=base::event::Factory::get("event.print");
	new_event->getArgs()->push_back(base::any::Factory::get(std::string("world!")));
	postEvent(new_event);
	
	new_event=base::event::Factory::get("event.shutdown");
	postEvent(new_event);
	
	for(base::event::signal_group_type::iterator it=_signal_group.begin(); it!=_signal_group.end(); ++it)
		std::cout<<it->first<<std::endl;
}

void TestApp::handleShutDown(base::event::Event* event)
{
	std::cout<<"[TestApp::handleShutDown]"<<std::endl;
	
	shutDown();
}

BASE_APP_MAIN(TestApp)
