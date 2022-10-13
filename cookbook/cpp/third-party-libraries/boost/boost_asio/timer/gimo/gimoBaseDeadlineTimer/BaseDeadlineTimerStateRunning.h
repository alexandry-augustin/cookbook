#ifndef BASEDEADLINETIMERSTATERUNNING_H
#define BASEDEADLINETIMERSTATERUNNING_H

#include <gimo/BaseTimerState.h>

class BaseDeadlineTimer;

class BaseDeadlineTimerStateRunning: public BaseTimerState
{
	BaseDeadlineTimer* _baseDeadlineTimer;
	
public:	
	BaseDeadlineTimerStateRunning(BaseDeadlineTimer* baseDeadlineTimer);
	
	void start();
	void stop();
	void pause();
	void resume();
};

#endif

