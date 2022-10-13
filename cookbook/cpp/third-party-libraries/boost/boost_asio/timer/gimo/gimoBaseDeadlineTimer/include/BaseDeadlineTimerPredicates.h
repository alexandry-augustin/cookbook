#ifndef BASEDEADLINETIMERPREDICATES_H
#define BASEDEADLINETIMERPREDICATES_H

#include <string>
#include <cassert>
#include <gimo/BaseDeadlineTimer.h>

namespace base {
namespace deadlineTimer {
namespace predicate {

class State:
	public std::unary_function<BaseDeadlineTimer*, bool>
{
	BaseDeadlineTimer::State		_state;

public:
	State(BaseDeadlineTimer::State state):
		_state(state)
	{
	}
	
	bool operator()(BaseDeadlineTimer const * const & timer) const
	{
		assert(timer!=NULL);
		
		return timer->getState()==_state;
	}
};

class Name:
	public std::unary_function<BaseDeadlineTimer*, bool>
{
	std::string		_name;

public:
	Name(std::string name):
		_name(name)
	{
	}
	
	bool operator()(BaseDeadlineTimer const * const & timer) const
	{
		assert(timer!=NULL);
		
		return timer->getName()==_name;
	}
};

} //namespace predicate
} //namespace deadlineTimer
} //namespace base

#endif
