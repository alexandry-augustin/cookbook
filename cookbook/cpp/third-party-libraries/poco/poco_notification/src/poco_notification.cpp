#include <iostream>
#include <cassert>
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/NotificationQueue.h"
#include "Poco/AutoPtr.h"
#include "Poco/NObserver.h"

class BaseNotification: public Poco::Notification
{
	int _data;

public:
	typedef Poco::AutoPtr<BaseNotification> Ptr;
	
	BaseNotification(int data):
		_data(data)
	{
	}
	
	int data() const
	{
		return _data;
	}
};

class BaseObserver
{
public:
	BaseObserver()
	{
	}

	void handleNotification(const Poco::AutoPtr<BaseNotification>& n)
	{
		std::cout<<"[BaseObserver::handleNotification] "<<n->data()<<std::endl;
	}
};

class BaseSubject
{
public:
	BaseSubject()
	{
	}
};

int main(int argc, char* argv[])
{
	BaseSubject subject;
	BaseObserver obs1, obs2;
	Poco::NotificationCenter nc;
	
	// synchronous
	
	nc.addObserver(Poco::NObserver<BaseObserver, BaseNotification>(obs1, &BaseObserver::handleNotification));
	nc.addObserver(Poco::NObserver<BaseObserver, BaseNotification>(obs2, &BaseObserver::handleNotification));
	
	nc.postNotification(new BaseNotification(0));
	
	// asynchronous
	
	Poco::NotificationQueue queue;
	
	for(int i=1; i<5; ++i)
		queue.enqueueNotification(new BaseNotification(i));
	
	//TODO print queue
	
//	while(!queue.empty())
//	{
//		
//		Poco::Notification::Ptr p=NULL;
//		//while(p!=NULL)
//		//	p=queue.dequeueNotification();
//		//or
//		p=queue.waitDequeueNotification();
//		BaseNotification::Ptr ptr=p.cast<BaseNotification>();
//		
//		nc.postNotification(ptr);
//		
//	}
	// or
	queue.dispatch(nc);
	
	nc.removeObserver(Poco::NObserver<BaseObserver, BaseNotification>(obs1, &BaseObserver::handleNotification));
	nc.removeObserver(Poco::NObserver<BaseObserver, BaseNotification>(obs2, &BaseObserver::handleNotification));
	
	return 0;
}