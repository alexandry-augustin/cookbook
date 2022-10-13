#ifndef MAIN_H
#define MAIN_H

#include "Poco/Util/ServerApplication.h"

class Main: public Poco::Util::ServerApplication
{
protected:
	/*virtual*/ void initialize(Application& self);
	/*virtual*/ void uninitialize();
	/*virtual*/ int main(const std::vector<std::string>& args);
};

#endif
