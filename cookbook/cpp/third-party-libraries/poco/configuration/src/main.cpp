#include <iostream>
#include "Poco/AutoPtr.h"
#include "Poco/Util/IniFileConfiguration.h"

int main()
{
	
	Poco::AutoPtr<Poco::Util::IniFileConfiguration> pConf(new Poco::Util::IniFileConfiguration("config/default.ini"));

	std::string path=pConf->getString("MyApplication.somePath");
	int value=pConf->getInt("MyApplication.someValue");
	value=pConf->getInt("myapplication.SomeValue");
	value=pConf->getInt("myapplication.SomeOtherValue", 456);
	std::cout<<path<<std::endl;
	
	return 0;
}
