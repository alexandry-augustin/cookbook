#include "BaseThread.h"
#include <iostream>

BaseThread::BaseThread(std::string name):
	//_thread(),
	_thread(NULL),
	_runnable(),
	_name(name)
{
}

BaseThread::BaseThread(std::string name, BaseRunnable_ptr runnable):
	//_thread(),
	_thread(NULL),
	_runnable(runnable),
	_name(name)
{
}

/*virtual*/ BaseThread::~BaseThread()
{
}

std::string BaseThread::getName() const
{
	return _name;
}

void BaseThread::setName(std::string name)
{
	_name=name;
}

void BaseThread::start()
{
	if(_thread==NULL)
	{
		if(_runnable==NULL)
			//_thread.reset(new boost::thread(boost::bind(&BaseThread::run, this)));
			_thread=new boost::thread(boost::bind(&BaseThread::run, this));
		else
			//_thread.reset(new boost::thread(boost::bind(&BaseRunnable::run, _runnable.get())));
			_thread=new boost::thread(boost::bind(&BaseRunnable::run, _runnable));
	}
}

/*virtual*/ void BaseThread::run()
{
	if(_runnable!=NULL)
		_runnable->run();
}

void BaseThread::join()
{
	if(_thread!=NULL)
		_thread->join();
}