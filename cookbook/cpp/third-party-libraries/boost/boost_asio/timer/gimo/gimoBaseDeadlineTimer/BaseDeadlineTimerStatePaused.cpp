#include "BaseDeadlineTimerStatePaused.h"
#include <gimo/BaseTimer.h>
#include "BaseDeadlineTimer.h"

BaseDeadlineTimerStatePaused::BaseDeadlineTimerStatePaused(BaseDeadlineTimer* baseTimer)
	: _baseTimer(baseTimer)
{

}

void BaseDeadlineTimerStatePaused::start()
{
}

void BaseDeadlineTimerStatePaused::stop()
{
}

void BaseDeadlineTimerStatePaused::pause()
{
}

void BaseDeadlineTimerStatePaused::resume()
{
}