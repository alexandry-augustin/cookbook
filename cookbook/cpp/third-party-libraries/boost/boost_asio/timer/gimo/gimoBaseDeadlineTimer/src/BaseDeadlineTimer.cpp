#include "BaseDeadlineTimer.h"
#include <iostream>
#include <sstream>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <gimo/BaseEvent.h>
#include <gimo/BaseSignal.h>
#include <gimo/BaseEventFactory.h>
#include <gimo/BaseException.h>
#include <gimo/BaseAny.h>
#include <gimo/BaseAnyFactory.h>
#include <gimo/Util.h>
#include "BaseTimeoutException.h"
/*#include "BaseDeadlineTimerStateRunning.h"
#include "BaseDeadlineTimerStatePaused.h"
#include "BaseDeadlineTimerStateStopped.h"*/

BaseDeadlineTimer::BaseDeadlineTimer(std::string name, boost::asio::io_service& io_service):
	_io_service(io_service),
	_timer(_io_service),
	_timeout(0),
	_name(name),
	_state(BaseDeadlineTimer::STATE_STOPPED_),
	_isResetting(false),
	_timeoutStr("timed_out"),
	_logLevel(1)
{
	_signalGroup["event.deadlinetimer_timedout"]=new event_signal_type();
}

SignalGroup* BaseDeadlineTimer::getSignalGroup()
{
	return &_signalGroup;
}

int BaseDeadlineTimer::getLogLevel() const
{
	return _logLevel;
}

void BaseDeadlineTimer::setLogLevel(int level)
{
	_logLevel=level;
}

std::string BaseDeadlineTimer::getTimeoutStr() const
{
	return _timeoutStr;
}

void BaseDeadlineTimer::setTimeoutStr(std::string str)
{
	_timeoutStr=str;
}

void BaseDeadlineTimer::pause()
{
	if(getState()!=BaseDeadlineTimer::STATE_RUNNING_) 
	{
		std::cerr<<"[BaseDeadlineTimer::pause] Timer ["<<getName()<<"] is not running."<<std::endl;
		assert(false);
		//throw BaseException("[BaseDeadlineTimer::pause] Timer ["+getName()+"] is not running");
		return;
	}
	
	std::cout<<"[BaseDeadlineTimer::pause] Pausing timer ["<<getName()<<"]."<<std::endl;
	
	//cancel any asynchronous operations waiting on the timer
	_timer.cancel();
	_pauseTime=BaseTime::now_u(); //TODO should be in handleTimer()
	
	setState(BaseDeadlineTimer::STATE_PAUSED_);
}

void BaseDeadlineTimer::resume()
{
	if(getState()!=BaseDeadlineTimer::STATE_PAUSED_) 
	{
		std::cerr<<"[BaseDeadlineTimer::resume] Timer ["<<getName()<<"] is not paused."<<std::endl;
		assert(false);
		//throw BaseException("[BaseDeadlineTimer::resume] Timer ["+getName()+"] is not paused");
		return;
	}
	
	boost::posix_time::time_duration pauseDuration=BaseTime::now_u().ptime()-_pauseTime.ptime();
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::resume] Resuming timer ["<<getName()<<"]. "
			<<"Paused for ["<<pauseDuration.total_milliseconds()<<"]ms."<<std::endl;
	_timer.expires_at(BaseTime::now_u().ptime()+boost::posix_time::seconds(getTimeout())+pauseDuration);
//	_timer.expires_from_now(boost::posix_time::seconds(getTimeout())); //equivalent
	_timer.async_wait(boost::bind(&BaseDeadlineTimer::handleTimeout, this, boost::asio::placeholders::error));
	
	setState(BaseDeadlineTimer::STATE_RUNNING_);
}

void BaseDeadlineTimer::setName(std::string name)
{
	_name=name;
}

std::string BaseDeadlineTimer::getName() const
{
	return _name;
}

void BaseDeadlineTimer::start()
{
	start(getTimeout());
}

void BaseDeadlineTimer::start(int timeout)
{
	if(getState()==BaseDeadlineTimer::STATE_RUNNING_)
	{
		std::cerr<<"[BaseDeadlineTimer::start] Timer ["<<getName()<<"] is already running."<<std::endl;
	//	assert(false);
	}
	
	setTimeout(timeout);
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::start] Starting timer ["<<getName()<<"] [timeout:"<<getTimeout()<<"]."<<std::endl;
	
	_startingTime=BaseTime::now_u();
	
	_timer.expires_at(BaseTime::now_u().ptime()+boost::posix_time::seconds(getTimeout()));
	//equivalent
//	_timer.expires_from_now(boost::posix_time::seconds(getTimeout())); 
	_timer.async_wait(boost::bind(&BaseDeadlineTimer::handleTimeout, this, boost::asio::placeholders::error));
	
	setState(BaseDeadlineTimer::STATE_RUNNING_);
}

void BaseDeadlineTimer::run(int timeout)
{
	if(getState()==BaseDeadlineTimer::STATE_RUNNING_)
	{
		std::cerr<<"[BaseDeadlineTimer::run] Timer ["<<getName()<<"] is already running."<<std::endl;
	//	assert(false);
		return;
	}
	
	setTimeout(timeout);
	
	run();
}

void BaseDeadlineTimer::run()
{
	if(getState()==BaseDeadlineTimer::STATE_RUNNING_)
	{
		std::cerr<<"[BaseDeadlineTimer::run] Timer ["<<getName()<<"] is already running."<<std::endl;
//		assert(false);
		return;
	}
	
/*	if(getTimeout()<0)
		throw BaseException("[BaseDeadlineTimer::run]");*/
	
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::run] Timer ["<<getName()<<"] is running. Timout is ["<<getTimeout()<<"]."<<std::endl;
	
	_timer.expires_from_now(boost::posix_time::seconds(getTimeout()));
	_timer.wait();
	
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::run] Timer ["<<getName()<<"] is stopped."<<std::endl;
	
	setState(BaseDeadlineTimer::STATE_STOPPED_);
}

void BaseDeadlineTimer::stop()
{
	if(getState()==BaseDeadlineTimer::STATE_STOPPED_)
	{
		std::cerr<<"[BaseDeadlineTimer::stop] Timer ["<<getName()<<"] is already stopped."<<std::endl;
		//assert(false);
		return;
	}
	
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::stop] Stopping timer ["<<getName()<<"]."<<std::endl;
	
	//cancel any asynchronous operations waiting on the timer
	_timer.cancel();
	
	setState(BaseDeadlineTimer::STATE_STOPPED_);
}

void BaseDeadlineTimer::restart(int timeout)
{
	if(getState()!=BaseDeadlineTimer::STATE_RUNNING_)
	{
		std::cerr<<"[BaseDeadlineTimer::restart] Timer ["<<getName()<<"] is not running."<<std::endl;
//		assert(false);
		return;
	}
	
	setTimeout(timeout);
	
	restart();
}

void BaseDeadlineTimer::restart()
{
	if(getState()!=BaseDeadlineTimer::STATE_RUNNING_)
	{
		std::cerr<<"[BaseDeadlineTimer::restart] Timer ["<<getName()<<"] is not running."<<std::endl;
//		assert(false);
		return;
	}
	
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::stop] Restarting timer ["<<getName()<<"]."<<std::endl;
	
	stop();
	
	start();
}

void BaseDeadlineTimer::setState(BaseDeadlineTimer::State state)
{
	_state=state;
}

BaseDeadlineTimer::State BaseDeadlineTimer::getState() const
{
	return _state;
}

int BaseDeadlineTimer::getTimeout() const
{
	return _timeout;
}

void BaseDeadlineTimer::setTimeout(int timeout)
{
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::stop] Timeout for BaseDeadlineTimer ["<<getName()<<"] set to ["<<timeout<<"]."<<std::endl;
	
	_timeout=timeout;
}

int BaseDeadlineTimer::getElapsedTime() const
{	
	if(getState()==BaseDeadlineTimer::STATE_STOPPED_)
		//return getTimeout();
		return 0;
	
	boost::posix_time::time_duration elapsedTime=BaseTime::now_u().ptime()-_startingTime.ptime();
/*	int elapsedTimeInSec=(int)elapsedTime.seconds();
	return elapsedTimeInSec<0?0:elapsedTimeInSec;*/
	return (int)elapsedTime.seconds();
}

int BaseDeadlineTimer::getRemainingTime()
{
	int remainingTime=getTimeout()-getElapsedTime();
	
	return remainingTime>0?remainingTime:0;
}

//TOREMOVE
bool BaseDeadlineTimer::isElapsed() const
{
	return false;//TODO
}

bool BaseDeadlineTimer::isResetting(bool isResetting)
{
	_isResetting=isResetting;
}

bool BaseDeadlineTimer::isResetting() const
{
	return _isResetting;
}

void BaseDeadlineTimer::handleTimeout(const boost::system::error_code& error)
{
	if(error)
	{
		if(error==boost::asio::error::operation_aborted)
		{
			if(getState()==BaseDeadlineTimer::STATE_STOPPED_)
				if(getLogLevel()==1)
					std::cout<<"[BaseDeadlineTimer::timeoutHandler] Timer ["<<getName()<<"] is stopped [timeElapsed:"<<getElapsedTime()<<"]."<<std::endl;
			
			if(getState()==BaseDeadlineTimer::STATE_PAUSED_)
				if(getLogLevel()==1)
					std::cout<<"[BaseDeadlineTimer::timeoutHandler] Timer ["<<getName()<<"] is paused [timeElapsed:"<<getElapsedTime()<<"]."<<std::endl;
			
			return;
		}
		
		std::cerr<<"[BaseDeadlineTimer::timeoutHandler] Error: "<<error.message()<<"."<<std::endl;
		
		return;
	}
	
	setState(BaseDeadlineTimer::STATE_STOPPED_);
	
	if(getLogLevel()==1)
		std::cout<<"[BaseDeadlineTimer::timeoutHandler] Timer ["<<getName()<<"] is timed-out [timeElapsed:"<<getElapsedTime()<<"]."<<std::endl;
	
	base::event::Event* event=base::event::Factory::get("event.deadlinetimer_timedout");
	event->setDebugInfo(_DEBUG_INFO_());
	event->getArgs()->push_back(base::any::Factory::get(_timeoutStr));
	base::event::notify(_signalGroup.find("event.deadlinetimer_timedout")->second, event);
	
	if(isResetting())
		start();	
}

std::string BaseDeadlineTimer::str() const
{
	std::stringstream ss;
	ss<<"[name:"<<_name<<"] ";
	ss<<"[state:"<<BaseDeadlineTimer::str(_state)<<"] ";
	ss<<"[timeout:"<<_timeout<<"] ";
	ss<<"[is_restting:"<<_isResetting<<"] ";
	ss<<"[log_level:"<<_logLevel<<"] ";
	
	return ss.str();
}

/*static*/ std::string BaseDeadlineTimer::str(BaseDeadlineTimer::State state)
{
	switch(state)
	{
	case BaseDeadlineTimer::STATE_RUNNING_:
		return "running";
	case BaseDeadlineTimer::STATE_PAUSED_:
		return "paused";
	case BaseDeadlineTimer::STATE_STOPPED_:
		return "stopped";
	default:
		assert(false);
		return "N/A";
	}
}