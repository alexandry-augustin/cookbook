// modeled after Java Thread class
// http://docs.oracle.com/javase/tutorial/essential/concurrency/runthread.html

// usage examples

// 1. by providing a BaseRunnable object:

// class MyClass_01: public BaseRunnable
// {
// public:
// 	/*virtual*/ void run()
// 	{
// 		std::cout<<"MyClass_01 is running..."<<std::endl;
// 	}
// };
// int main()
// {
// 	MyClass_01 my_class_01;
// 	BaseThread thread(&my_class_01);
// 	thread.start();
// 	thread.join();
// 
// 	boost::shared_ptr<MyClass_01> my_class_01(new MyClass_01());
// 	BaseThread* thread=new BaseThread(my_class_01);
// 	thread->run();
// 	thread->join();
// 
// 	return 0;
// }

// 2. by subclassing BaseThread:

// class MyClass_02: public BaseThread
// {
// public:
// 	/*virtual*/ void run()
// 	{
// 		std::cout<<"MyClass_02 is running..."<<std::endl;
// 	}
// };
// int main()
// {
// 	MyClass_02 my_class_02;
// 	my_class_02.start();
// 	my_class_02.join();
// 
// 	boost::shared_ptr<MyClass_02> my_class_02(new MyClass_02());
// 	my_class_02->run();
// 	my_class_02->join();
//
// 	return 0;
// }
