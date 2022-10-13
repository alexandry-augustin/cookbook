#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//---------------------------------------------------------
boost::asio::io_service		global_io_service;
//---------------------------------------------------------
void check_thread_id_00(boost::thread::id id)
{
	assert(boost::this_thread::get_id()==id);
}
//---------------------------------------------------------
void check_thread_id_01(boost::thread::id id)
{
	assert(boost::this_thread::get_id()!=id);
}
//---------------------------------------------------------
void run_00()
{
	std::cout<<"running"<<std::endl;
}
//---------------------------------------------------------
void run_01(boost::asio::io_service& io_service, boost::thread::id id)
{
	io_service.post(boost::bind(check_thread_id_01, id));
	io_service.post(boost::bind(check_thread_id_00, boost::this_thread::get_id()));
	io_service.poll();
}
//---------------------------------------------------------
void thread_00()
{
	global_io_service.post(boost::bind(check_thread_id_00, boost::this_thread::get_id()));
}
//---------------------------------------------------------
void thread_01()
{
	global_io_service.post(run_00);
}
//---------------------------------------------------------
int main()
{
	{
		boost::asio::io_service		io_service;

		io_service.post(boost::bind(check_thread_id_00, boost::this_thread::get_id()));
		io_service.poll_one();
	}
	{
		boost::thread t_00(thread_01);
		t_00.join();
		global_io_service.run();
	}
	/*{
		boost::thread_group		thread_group;

		for(int i=0; i<2; ++i)
			thread_group.create_thread(thread_00);
		thread_group.join_all();
	}*/
	{
		boost::asio::io_service		io_service;
		boost::thread_group		thread_group;
	
		for(int i=0; i<5; ++i)
			thread_group.create_thread(
				boost::bind(run_01, boost::ref(io_service), boost::this_thread::get_id()));
		thread_group.join_all();
	}
	{
		//timer.async_wait(boost::bind(check_thread_id_00, boost::this_thread::get_id()));
	}
	return 0;
}
