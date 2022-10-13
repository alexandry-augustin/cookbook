/*
http://stackoverflow.com/questions/130117/throwing-exceptions-out-of-a-destructor

an exception should be thrown if and only if a function's postconditions cannot be met. The postcondition of a destructor is that the object no longer exists. This can't not happen. Any failure-prone end-of-life operation must therefore be called as a separate method before the object goes out of scope (sensible functions normally only have one success path anyway).
*/
/*
http://stackoverflow.com/questions/130117/throwing-exceptions-out-of-a-destructor

Throwing out of a destructor can result in a crash, because this destructor might be called as part of "Stack unwinding". Stack unwinding is a procedure which takes place when an exception is thrown. In this procedure, all the objects that were pushed into the stack since the "try" and until the exception was thrown, will be terminated -> their destructors will be called. And during this procedure, another exception throw is not allowed, because it's not possible to handle two exceptions at a time, thus, this will provoke a call to abort(), the program will crash and the control will return to the OS.
*/
/*
http://msdn.microsoft.com/en-us/library/hh254939.aspx
Exceptions and Stack Unwinding in C++

In the C++ exception mechanism, control moves from the throw statement to the first catch statement that can handle the thrown type. When the catch statement is reached, all of the automatic variables that are in scope between the throw and catch statements are destroyed in a process that is known as stack unwinding. In stack unwinding, execution proceeds as follows:

1-Control reaches the try statement by normal sequential execution. The guarded section in the try block is executed.

2-If no exception is thrown during execution of the guarded section, the catch clauses that follow the try block are not executed. Execution continues at the statement after the last catch clause that follows the associated try block.

3-If an exception is thrown during execution of the guarded section or in any routine that the guarded section calls either directly or indirectly, an exception object is created from the object that is created by the throw operand. (This implies that a copy constructor may be involved.) At this point, the compiler looks for a catch clause in a higher execution context that can handle an exception of the type that is thrown, or for a catch handler that can handle any type of exception. The catch handlers are examined in order of their appearance after the try block. If no appropriate handler is found, the next dynamically enclosing try block is examined. This process continues until the outermost enclosing try block is examined.

4-If a matching handler is still not found, or if an exception occurs during the unwinding process but before the handler gets control, the predefined run-time function std::terminate() is called. If an exception occurs after the exception is thrown but before the unwind begins, std::terminate() is called.

5-If a matching catch handler is found, and it catches by value, its formal parameter is initialized by copying the exception object. If it catches by reference, the parameter is initialized to refer to the exception object. After the formal parameter is initialized, the process of unwinding the stack begins. This involves the destruction of all automatic objects that were fully constructed—but not yet destructed—between the beginning of the try block that is associated with the catch handler and the throw site of the exception. Destruction occurs in reverse order of construction. The catch handler is executed and the program resumes execution after the last handler—that is, at the first statement or construct that is not a catch handler. Control can only enter a catch handler through a thrown exception, never through a goto statement or a case label in a switch statement.

The following example demonstrates how the stack is unwound when an exception is thrown. Execution on the thread jumps from the throw statement in C to the catch statement in main, and unwinds each function along the way. Notice the order in which the Dummy objects are created and then destroyed as they go out of scope. Also notice that no function completes except main, which contains the catch statement. Function A never returns from its call to B(), and B never returns from its call to C(). If you uncomment the definition of the Dummy pointer and the corresponding delete statement, and then run the program, notice that the pointer is never deleted. This shows what can happen when functions do not provide an exception guarantee. If you comment out the catch statement, you can observe what happens when a program terminates because of an unhandled exception.
*/

#include <cassert>
#include <string>
#include <typeinfo>
#include <iostream>

struct MyException
{
	MyException()
	{
		std::cout<<"MyException::MyException\n";
	}
	~MyException()
	{
		std::cout<<"MyException::~MyException\n";
	}
};

struct Dummy
{
	std::string _name; 

	Dummy(std::string name):
		_name(name)
	{
		std::cout<<"Dummy::Dummy("<<_name<<")\n";
	}
	Dummy(const Dummy& other):
		_name(other._name)
	{
		std::cout<<"Dummy::Dummy(const Dummy& other) ("<<_name<<")\n";
	}
	~Dummy()
	{
		std::cout<<"Dummy::~Dummy ("<<_name<<")\n";
	}
};

void C(Dummy d, int i)
{ 
	std::cout<<"entering C(...)"<<std::endl;
	d._name="C";
	throw MyException();   
	std::cout<<"exiting C(...)"<<std::endl;
}

void B(Dummy d, int i)
{
	std::cout<<"entering B(...)"<<std::endl;
	d._name="B";
	C(d, i+1);   
	std::cout<<"exiting B(...)"<<std::endl; 
}

void A(Dummy d, int i)
{ 
	std::cout<<"entering A(...)"<<std::endl;
	d._name="A" ;
	//Dummy* pd=new Dummy("new Dummy"); //Not exception safe!!!
	B(d, i+1);
	//delete pd; 
	std::cout<<"exiting A(...)"<<std::endl;   
}

int main()
{
	{
		std::cout<<"entering main"<<std::endl;
		try
		{
			Dummy d("M");
			A(d, 1);
		}
		catch(MyException& e)
		{
			std::cerr<<"exception: "<<typeid(e).name()<<std::endl;
		}
		std::cout<<"exiting main"<<std::endl;
	}
	return 0;
}
