#include <iostream>
#include <string>
#include <boost/thread.hpp>

boost::mutex mutex_00;
boost::mutex mutex_01;

void thread_00()  
{  
	mutex_00.lock();  
	mutex_01.lock();  

	boost::posix_time::seconds ptime(5);
	boost::this_thread::sleep(ptime);

	mutex_00.unlock();  
	mutex_01.unlock();  
}  
void thread_01()  
{  
	mutex_01.lock();  
	mutex_00.lock();  

	boost::posix_time::seconds ptime(3);
	boost::this_thread::sleep(ptime);

	mutex_01.unlock();  
	mutex_00.unlock();  
}  
int main()
{
	boost::thread thread_0(thread_00);
	boost::thread thread_1(thread_01);

	thread_1.join();
	//thread_2.join();
}
