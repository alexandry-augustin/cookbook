//http://antonym.org/2009/05/threading-with-boost---part-i-creating-threads.html

#include <iostream>
#include <string>
#include <boost/thread.hpp>
using namespace std;

//boost threads do not support cancellation (Cancellation is troublesome, because 
//the canceled thread might not execute C++ destructors or release locks on the way out ... 
//but then again it might; the uncertainty is actually worse than a definitive no.)

void fct01()
{
	cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;

    boost::posix_time::seconds workTime(3);
	boost::this_thread::sleep(workTime);

	cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
}

void fct02(string msg, float delay_ms)
{
	cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;
    
	cout << "Message = " << msg << endl;
    boost::posix_time::milliseconds workTime(delay_ms);
    boost::this_thread::sleep(workTime);

	cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
}


class myFunctor
{
    int m_n;
public:
    myFunctor(int value) : m_n(value) {}

    void operator()()
    {
		cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;

		boost::posix_time::milliseconds workTime(3);
		boost::this_thread::sleep(workTime);

		cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
    }
};
//Note: A very important consideration when using functors with 
//boost threads is that the thread constructor takes the functor 
//parameter by value, and thus makes a copy of the functor object. 
//Depending on the design of your functor object, this may have 
//unintended side-effects. Take care when writing functor objects 
//to ensure that they can be safely copied.

class myClass01
{
    int m_n;
public:
    myClass01(int value=3) : m_n(value) {}

    void fct01()
    {
		cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;

		boost::posix_time::milliseconds workTime(3);
		boost::this_thread::sleep(workTime);

		cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
    }

    void fct02(string msg, float delay_ms)
    {
		cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;
	    
		cout << "Message = " << msg << endl;
		boost::posix_time::milliseconds workTime(delay_ms);
		boost::this_thread::sleep(workTime);

		cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
    }
};
//Note: Because methods in C++ always have an implicit this pointer passed in as the first parameter, 
//we need to make sure we call the object's method using the same convention. 
//So we will pass the object pointer (or this depending on whether we are inside the object or not) 
//as the first parameter, along with any other actual parameters we might have after that.

class myClass02
{
	boost::thread    m_thread; // the default constructor for the thread creates it in an "invalid" state, called not-a-thread
public:
    myClass02() {}

    void start(int n) { m_thread = boost::thread(&myClass02::fct, this, n); }
    void join() { m_thread.join(); }
    void fct(int n)
    {
		cout << "Thread "<<boost::this_thread::get_id()<< " running." << endl;

		boost::posix_time::milliseconds workTime(n);
		boost::this_thread::sleep(workTime);

		cout << "Thread "<<boost::this_thread::get_id()<< " finished." << endl;
    }
};

int main__()
{   
	cout << "Main: startup" << endl;
	cout << "Main: ID = " << boost::this_thread::get_id() << endl;
	
	boost::thread n(fct01);
	cout << "Main: waiting for thread " << n.get_id() << endl;
	n.join();
	
	boost::thread o(fct02, "Hello, Boost!", 2.5e3f);
	cout << "Main: waiting for thread " << o.get_id() << endl;
	o.join();
 
	boost::thread m(myFunctor(5));
	cout << "Main: waiting for thread " << o.get_id() << endl;
    m.join();	//Wait for the worker thread to complete
					//This will cause the main thread to sleep until the worker thread completes (successfully or otherwise).

	myClass01 h;  
	boost::thread v(&myClass01::fct01, &h);  
	cout << "Main: waiting for thread " << v.get_id() << endl;
	v.join();

	myClass01 p(3);  
	boost::thread u(&myClass01::fct02, &p, "msg", 2.0f);  
	cout << "Main: waiting for thread " << u.get_id() << endl;
	u.join();

	//As an aside, take care in your own code that you don't accidentally allocate an object on the stack in one place, spawn a thread, then have the object go out of scope and be destroyed before the thread has completed! This could be the source of many tricky bugs.

    myClass02 k;
    k.start(3);
	//cout << "Main: waiting for thread " << u.get_id() << endl;
    k.join();

    cout << "Main: done" << endl;

	return 0;
}

// A mutex is used to serialise access to resources within a region of code that must run as an atomic operation. 
