#ifndef BASEAPP_H
#define BASEAPP_H

#include <queue>
#include <string>
#include <map>
#include <vector>
//#include <boost/function.hpp>
//#include <boost/thread.hpp>
//#include <gimo/BaseSignal.h>

class BaseApp
{
private:
	boost::mutex				_mutex;
	std::queue<base::event::Event*>		_event_queue;
	bool					_run;
	
protected:
	int					_idle_sleep_time;	//[ms]
	int					_lag_simulation;	//[ms]
//	boost::thread_group*			_thread_group;
//	base::event::signal_group_type		_signal_group;
	
	virtual void run();
	
public:
	BaseApp();
	virtual ~BaseApp();
	
	virtual void init(std::vector<std::string> args);
	virtual void startup();
	virtual void shutDown();
	virtual void finalize();
	virtual void postEvent(Event* event);
	virtual void connectEventHandler(std::string type, boost::function<void (base::event::Event*)> handler);
	virtual int main(int argc, char* argv[]);

};

#endif
