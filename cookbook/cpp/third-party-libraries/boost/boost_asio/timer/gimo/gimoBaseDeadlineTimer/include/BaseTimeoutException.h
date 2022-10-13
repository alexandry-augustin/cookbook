#ifndef BASETIMEOUTEXCEPTION_H
#define BASETIMEOUTEXCEPTION_H

#include <exception>
#include <string>

class BaseDeadlineTimer;

class BaseTimeoutException:
	public std::exception
{
	std::string 		m_message; //explanatory message
	BaseDeadlineTimer*	m_timer;

public:
	BaseTimeoutException(BaseDeadlineTimer* timer, const std::string& message, bool inclSysMsg=false) throw();
	~BaseTimeoutException() throw();
	
	BaseDeadlineTimer* getTimer() const;
	const char* what() const throw();
};

#endif
