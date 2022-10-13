#ifndef BASEDEADLINETIMER_H
#define BASEDEADLINETIMER_H

#include <string>
#include <map>
#include <boost/asio.hpp>
#include <boost/signals.hpp>
#include <gimo/BaseTime.h>

class BaseDeadlineTimerState;
namespace base {
class Any;
namespace event {
class Event;
} //namespace event
} //namespace base
//   _timer.expires_at(boost::posix_time::pos_infin);

typedef boost::signal<void (base::event::Event*)>	event_signal_type;
typedef std::map<std::string, event_signal_type*>	SignalGroup;
class BaseDeadlineTimer
{
public:
	//TODO
	enum State
	{
		STATE_RUNNING_,
		STATE_PAUSED_,
		STATE_STOPPED_
	};
	
private:
	BaseDeadlineTimerState*		_baseDeadlineTimerStateRunning;
	BaseDeadlineTimerState*		_baseDeadlineTimerStatePaused;
	BaseDeadlineTimerState*		_baseDeadlineTimerStateStopped;
	BaseDeadlineTimerState*		_currentState;
	boost::asio::io_service& 	_io_service;
	boost::asio::deadline_timer	_timer;
	std::string			_name;
	BaseDeadlineTimer::State	_state;
	bool				_isResetting;
	int				_logLevel;
	BaseTime			_startingTime;
	BaseTime			_pauseTime;
	int				_timeout;
	std::string			_timeoutStr;
	SignalGroup			_signalGroup;
	
	void handleTimeout(const boost::system::error_code& error);
	
public:
	BaseDeadlineTimer(std::string name, boost::asio::io_service& io_service);
	
	SignalGroup* getSignalGroup();
	void start();
	void start(int timeout);
//str notified when timedout
std::string getTimeoutStr() const;
void setTimeoutStr(std::string str);
	void run(); 
	void run(int timeout);
	void pause();
	void resume();
	void stop();
	void restart();
	void restart(int timeout);
	bool isElapsed() const;
	bool isResetting() const;
	bool isResetting(bool isResetting);
	int getLogLevel() const;
	BaseDeadlineTimer::State getState() const;
	int getElapsedTime() const; //TOREMOVE
	int getRemainingTime();
	int getTimeout() const;
	std::string getName() const;
	void setName(std::string name);
	void setLogLevel(int level);
	void setTimeout(int timeout);	
	void setState(BaseDeadlineTimer::State state);
	std::string str() const;
	static std::string str(BaseDeadlineTimer::State state);
	
};

#endif

