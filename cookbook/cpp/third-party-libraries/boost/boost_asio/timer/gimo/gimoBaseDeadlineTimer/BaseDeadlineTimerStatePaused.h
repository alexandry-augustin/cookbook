#ifndef BASEDEADLINETIMERSTATEPAUSED_H
#define BASEDEADLINETIMERSTATEPAUSED_H

#include <gimo/BaseTimerState.h>

class BaseDeadlineTimer;

class BaseDeadlineTimerStatePaused: public BaseTimerState
{
	BaseDeadlineTimer* _baseDeadlineTimer;
	
public:	
	BaseDeadlineTimerStatePaused(BaseDeadlineTimer* baseDeadlineTimer);
	
	void start();
	void stop();
	void pause();
	void resume();
};

#endif

