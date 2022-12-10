#include "BaseException.h"
#include <iostream>
#include <string.h>	//strerror
#include <errno.h>	//errno

namespace base {

Exception::Exception(const std::string& message, bool inclSysMsg) throw()
	: m_message(message)
{
	if(inclSysMsg)
	{
		m_message.append(": ");
		m_message.append(strerror(errno));
	}
}

Exception::~Exception() throw()
{

}

const char* Exception::what() const throw()
{
	return m_message.c_str();
}

} //namespace base
