#include "BaseApp.h"
#include <iostream>
#include <gimo/BaseEvent.h>

BaseApp::BaseApp():
	_thread_group(new boost::thread_group()),
	_idle_sleep_time(5),
	_lag_simulation(0),
	_run(true)
{
}

/*virtual*/ BaseApp::~BaseApp()
{
}

/*virtual*/ int BaseApp::main(int argc, char* argv[])
{
	init(std::vector<std::string>(argv, argv+argc));
	startup();
	_thread_group->join_all();
	finalize();
}

/*virtual*/ void BaseApp::init(std::vector<std::string> args)
{

}

/*virtual*/ void BaseApp::startup()
{
	_thread_group->create_thread(boost::bind(&BaseApp::run, this));
}

/*virtual*/ void BaseApp::shutDown()
{
	_run=false;
}

/*virtual*/ void BaseApp::finalize()
{

}

/*virtual*/ void BaseApp::connectEventHandler(std::string type, boost::function<void (base::event::Event*)> handler)
{
	//base::event::signal_group_type::const_iterator it=_signal_group.find(type);
	if(_signal_group.find(type)==_signal_group.end())
		_signal_group.insert(std::make_pair(type, new base::event::event_signal_type()));
	
	_signal_group.find(type)->second->connect(handler);
}

/*virtual*/ void BaseApp::postEvent(base::event::Event* event)
{
//	boost::lock_guard<boost::mutex> guard(_mutex);
	
	_event_queue.push(event);
	
	//std::cout<<"[BaseApp::postEvent] Event ["<<event->getType()<<"] posted."<<std::endl;
}

/*virtual*/ void BaseApp::run()
{
	base::event::Event* event=NULL;
	
	//"event.base.app.idle"
	try
	{
		while(_run)
		{
			boost::this_thread::interruption_point();
			
			if(_lag_simulation>0)
				boost::this_thread::sleep(boost::posix_time::milliseconds(_lag_simulation));
			
			if(_event_queue.empty())
			{
				//avoid using cpu resources when idle
				if(_idle_sleep_time>0)
					boost::this_thread::sleep(boost::posix_time::milliseconds(_idle_sleep_time));
				
				continue;
			}
			
			event=_event_queue.front();
			assert(event!=NULL);
			_event_queue.pop();
			
			//dispatch event for processing by all observers sequentially (single thread)
			//std::cout<<"[BaseApp::run] Dispatching event ["<<event->getType()<<"] "
			//	<<"[debug_info:"<<event->getDebugInfo()<<"]."<<std::endl;
			base::event::notify(&_signal_group, event);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr<<"[BaseApp::run] Exception: "<<e.what()<<std::endl;
		assert(false);
	}
	
	finalize();
}
