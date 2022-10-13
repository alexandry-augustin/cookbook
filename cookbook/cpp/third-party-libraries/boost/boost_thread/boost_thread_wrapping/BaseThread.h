#ifndef BASETHREAD_H
#define BASETHREAD_H

#include <boost/thread.hpp>
#include <string>
#include "BaseRunnable.h"

class BaseThread:
	public BaseRunnable
{
	//typedef boost::shared_ptr<boost::thread>	boost_thread_ptr;
	//typedef boost::shared_ptr<BaseRunnable>		BaseRunnable_ptr;
	typedef boost::thread*				boost_thread_ptr;
	typedef BaseRunnable*				BaseRunnable_ptr;
	
	boost_thread_ptr	_thread;
	BaseRunnable_ptr	_runnable;
	std::string		_name;

public:
	BaseThread(std::string name);
	BaseThread(std::string name, BaseRunnable_ptr runnable);
	virtual ~BaseThread();
	
	std::string getName() const;
	void setName(std::string name);
	/*virtual*/ void run();
	void start();
	void join();
};

#endif
