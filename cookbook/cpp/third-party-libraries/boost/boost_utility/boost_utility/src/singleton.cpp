/*#include <iostream>
#include <string>


//three Singleton templates that share an identical interface implementing identical behavior in a single-threaded environment differing in the following properties in multi-threaded context:
//
//boost::singleton can be used to create Singletons with synchronized initialization. If further synchronization is required it has to be implemented by the user.
//boost::mutexed_singleton additionally ensures that concurrent access to the instance is mutually exclusive. In other words, only one thread can access the instance at a given time.
//boost::thread_specific_singleton instances exist once per thread.

#include <boost/utility/singleton.hpp>
//#include <boost/utility/mutexed_singleton.hpp>
//#include <boost/utility/thread_specific_singleton.hpp>

class myClass: public boost::singleton<myClass>
{
	std::string m_str;

public:
	myClass(boost::restricted);

	void set(std::string str) { m_str=str; }
	std::string get() const { return m_str; }
};

int main_(int argc, char* argv[])
{
	myClass::instance->set("Hello World!");
	std::cout<<myClass::instance->get()<<std::endl;

	return 0;
}*/
