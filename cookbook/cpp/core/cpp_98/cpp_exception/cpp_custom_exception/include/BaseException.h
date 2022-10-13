#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

namespace base {

class Exception: public std::exception
{
	std::string m_message; //explanatory message
public:
	Exception(const std::string& message, bool inclSysMsg=false) throw();
	~Exception() throw();

	const char* what() const throw();
};

} //namespace base

#endif
