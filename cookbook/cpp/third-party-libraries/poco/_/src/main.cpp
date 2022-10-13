#include <iostream>
#include "Poco/Notification.h"
#include "Poco/NotificationQueue.h"
#include "Poco/ThreadPool.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/Mutex.h"
#include "Poco/Random.h"
#include "Poco/AutoPtr.h"

class WorkNotification: public Poco::Notification
{
	int _data;
public:
	typedef Poco::AutoPtr<WorkNotification> Ptr;
	
	WorkNotification(int data):
		_data(data)
	{
	}
	int data() const
	{
		return _data;
	}
};

class Worker: public Poco::Runnable
{
	std::string	        	_name;
	Poco::NotificationQueue& 	_queue;
	static Poco::FastMutex   	_mutex;

public:
	Worker(const std::string& name, Poco::NotificationQueue& queue):
		_name(name),
		_queue(queue)
	{
	}
	
	void run()
	{
		Poco::Random rnd;
		for(;;)
		{
			Poco::Notification::Ptr pNf(_queue.waitDequeueNotification());
			if (pNf)
			{
				WorkNotification::Ptr pWorkNf = pNf.cast<WorkNotification>();
				if (pWorkNf)
				{
					{
						Poco::FastMutex::ScopedLock lock(_mutex);
						std::cout << _name << " got work notification " << pWorkNf->data() << std::endl;
					}
					Poco::Thread::sleep(rnd.next(200));
				}
			}
			else
				break;
		}
	}
};

Poco::FastMutex Worker::_mutex;

int main(int argc, char** argv)
{
	Poco::NotificationQueue queue;
	
	Worker worker1("Worker 1", queue);
	Worker worker2("Worker 2", queue);
	Worker worker3("Worker 3", queue);

	Poco::ThreadPool::defaultPool().start(worker1);
	Poco::ThreadPool::defaultPool().start(worker2);
	Poco::ThreadPool::defaultPool().start(worker3);

	for(int i=0; i<50; ++i)
		queue.enqueueNotification(new WorkNotification(i));

	// wait until queue is empty and all threads are 
	// waiting for new work.
	while(!queue.empty())
		Poco::Thread::sleep(200);
	Poco::Thread::sleep(500);

	// stop all worker threads
	queue.wakeUpAll();
	Poco::ThreadPool::defaultPool().joinAll();

	return 0;
}
