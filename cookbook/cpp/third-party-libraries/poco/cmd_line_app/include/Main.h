#ifndef MAIN_H
#define MAIN_H

#include "Poco/Util/Application.h"

class Main: public Poco::Util::Application
{
protected:
	/*virtual*/ void initialize(Poco::Util::Application& self);
	
	/*virtual*/ void uninitialize();
	
	/*virtual*/ void reinitialize(Poco::Util::Application& self);
	
	/*virtual*/ void defineOptions(Poco::Util::OptionSet& options);
	
	int main(const std::vector<std::string>& args);
};

#endif
