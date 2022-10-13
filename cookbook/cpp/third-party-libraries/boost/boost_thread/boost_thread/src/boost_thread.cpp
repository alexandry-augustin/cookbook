#include <string>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
//---------------------------------------------------------
bool volatile done=false;
//---------------------------------------------------------
void run_00()
{
	std::cout<<"[run_00]"<<std::endl;
}
//---------------------------------------------------------
void run_01()
{
	std::cout<<"[run_01]"<<std::endl;
}
//---------------------------------------------------------
void run_02()
{
	done=true;
}
//---------------------------------------------------------
void run_03()
{
	boost::posix_time::milliseconds ptime(100);
	while(!done)
		boost::this_thread::sleep(ptime);
}
//---------------------------------------------------------
class base_00
{
	int			_n;
	mutable boost::mutex	_mutex_00;
public:
	base_00(int n=0): _n(n) {}
	void set(int n)
	{
		_mutex_00.lock();  
		_n=n;
		_mutex_00.unlock();  
	}
	int get() const
	{
		_mutex_00.lock();  
		int n=_n;	
		_mutex_00.unlock();  
		return n;
	}
};
//---------------------------------------------------------
struct base_01
{
	void operator()()
	{
	}
};
//---------------------------------------------------------
int main()
{
	{
		base_01 b_01;

		boost::thread thread_00(base_01);//????
		boost::thread thread_01(b_01);
	}
	{
		boost::thread* thread0=new boost::thread(run_00);
		boost::thread_group thread_group; //non copyable

		thread_group.add_thread(thread0);
		thread_group.create_thread(run_01);
		thread_group.join_all();
	}
	{
		base_00 b;
		//boost::thread thread_0(boost::bind(&base::run_00, &b));
		//boost::thread thread_1(boost::bind(&base::run_00, &b));

		//thread_0.join();
		//thread_1.join();
	}
	{
		boost::thread thread0(run_03);
		boost::thread thread1(run_02);
		thread0.join();
	}
	return 0;
}
