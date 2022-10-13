#ifndef BASEDEADLINETIMERSTATESTOPPED_H
#define BASEDEADLINETIMERSTATESTOPPED_H

#include <gimo/BaseTimerState.h>

class BaseDeadlineTimer;

class BaseDeadlineTimerStateStopped: public BaseTimerState
{
	BaseDeadlineTimer* _baseDeadlineTimer;
	
public:	
	BaseDeadlineTimerStateStopped(BaseDeadlineTimer* baseDeadlineTimer);
	
	void start();
	void stop();
	void pause();
	void resume();
};

#endif

