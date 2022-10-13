#include "BaseTimeoutException.h"
#include <iostream>
#include <string.h>	//strerror
#include <errno.h>	//errno
#include "BaseDeadlineTimer.h"

BaseTimeoutException::BaseTimeoutException(BaseDeadlineTimer* timer, const std::string& message, bool inclSysMsg) throw():
	m_message(message),
	m_timer(timer)
{
	if(inclSysMsg)
	{
		m_message.append(": ");
		m_message.append(strerror(errno));
	}
}

BaseTimeoutException::~BaseTimeoutException() throw()
{

}

BaseDeadlineTimer* BaseTimeoutException::getTimer() const
{
	return m_timer;
}

const char* BaseTimeoutException::what() const throw()
{
	return m_message.c_str();
}