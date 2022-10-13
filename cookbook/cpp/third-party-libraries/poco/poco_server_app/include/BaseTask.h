#ifndef BASETASK_H
#define BASETASK_H

#include "Poco/Task.h"

class BaseTask: public Poco::Task
{
public:
	BaseTask();
	
	void runTask();
};

#endif
