#include <iostream>
#include <string>
#include <boost/thread.hpp>

boost::condition_variable condition_variable;
boost::mutex mutex;
bool data_ready;

void process_data()
{
}

void wait_for_data_to_process()
{
	boost::unique_lock<boost::mutex> unique_lock(mutex);
	while(!data_ready)
	{
		condition_variable.wait(unique_lock);
	}
	process_data();
}

int main()
{
}
