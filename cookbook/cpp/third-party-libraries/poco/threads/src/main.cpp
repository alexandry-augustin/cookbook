#include <iostream>
#include "Poco/Thread.h"
#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include "Poco/Mutex.h"

class BaseThread: public Poco::Runnable
{
	static Poco::FastMutex   	_mutex;

public:
	/*virtual*/ void run()
	{
		Poco::FastMutex::ScopedLock lock(_mutex);
		std::cout<<"[BaseThread::run]"<<std::endl;
		Poco::Thread::sleep(1000);
	}
};

Poco::FastMutex BaseThread::_mutex;

int main()
{
	BaseThread t;
	Poco::ThreadPool::defaultPool().start(t);
	Poco::ThreadPool::defaultPool().joinAll();
	
	return 0;
}