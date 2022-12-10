#include <cassert>
#include <iostream>
#include <thread>

class base
{
public:
	void operator()()
	{
		std::cout<<"running"<<std::endl;
	}
};

int main()
{
	{
		std::thread thread(base);
		//thread.detach();
		thread.join();
	}
	{
		base b;
		std::thread thread(std::ref(b));
	}
	return 0;
}
