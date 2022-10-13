#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cassert>
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

// http://en.highscore.de/cpp/boost/eventhandling.html

struct base
{
	int n;
	base(int m): n(m) { }
	void handleEvent(int m)	{ n=m; }
};

struct EventGenerator
{
	boost::signal<void ()>    generateEventA;
	boost::signal<void (int)> generateEventB;
};

struct EventHandler
{
	void handleEventA()
	{
		std::cout<<"handleEventA::"<<std::endl;
	}
	void handleEventB(int i)
	{
		std::cout<<"handleEventB::"<<i<<std::endl;
	}
};

class EventDispatcher
{
	std::list<EventGenerator*>	m_generator;
	std::list<EventHandler*>	m_handler;

public:
	EventDispatcher(const std::list<EventGenerator*>& generator, const std::list<EventHandler*>& handler)
		: m_generator(generator),
		m_handler(handler)
	{
	}
};

void handleEvent(int n)
{
	std::cout<<n<<std::endl;
}

void handler1(std::string str)
{
	std::cout<<"[obs1] "<<str<<std::endl;
}

void handler2(std::string str)
{
	std::cout<<"[obs2] "<<str<<std::endl;
}

void connect(boost::signal<void (std::string)>& sig, const boost::signal<void (std::string)>::slot_type& slot) 
{
	sig.connect(slot);
}

class Button 
{
	typedef boost::signal<void (int x, int y)> OnClick;

	OnClick onClick;
public:
	void doOnClick(const OnClick::slot_type& slot)
	{
		onClick.connect(slot);
	}
};

void printCoordinates(long x, long y)
{
	std::cout<<"("<<x<<", "<<y<<")"<<std::endl;
}

void f(Button& button)
{
	button.doOnClick(&printCoordinates);
}

void notify_(boost::signal<void (int)>* signal, int n)
{
	signal->operator()(n);
}

int main()
{
	{
		boost::signal<void (std::string)> sig;
		sig("no obs");
	}
	{
		boost::signal<void (std::string)> sig;
		sig.connect(handler1);
		//or
		//sig.connect(&handler1);
		//or
		//connect(sig, &handler1);
		sig.connect(handler2);
		sig("Hello World!");
		
		sig.disconnect(handler2);
		sig("Hello World!");
	
		sig.disconnect_all_slots();
		sig("Hello World!");
	}
	{
		base b(5);

		boost::signal<void (int)> sig_base;
		sig_base.connect(boost::bind(&base::handleEvent, &b, _1));
		sig_base(10);
	}
	{
		EventGenerator a;
		EventHandler b1, b2;

		a.generateEventA.connect(boost::bind(&EventHandler::handleEventA, &b1));
		a.generateEventB.connect(boost::bind(&EventHandler::handleEventB, &b1, _1));
		a.generateEventB.connect(boost::bind(&EventHandler::handleEventB, &b2, _1));

		a.generateEventA();
		a.generateEventB(4);
	}
	{
		base b(0);
		boost::function<void (int)> handler;
		boost::signal<void (int)> sig_base;
		
//		handler=handleEvent;
		handler=boost::bind(&base::handleEvent, &b, _1);
	
		sig_base.connect(boost::bind(handler, _1));
		sig_base(10);
		assert(b.n==10);

	}
	{
		boost::signal<void (int)> sig;
		
		assert(sig.empty());
		sig.connect(handleEvent);
		assert(!sig.empty());
		assert(sig.num_slots()==1);
	}
	{
		boost::signal<void (int)>	signal;
		boost::function<void (int)>	notify;

		signal.connect(handleEvent);

		notify=boost::bind(boost::ref(signal), _1);
		notify(10);
	
		notify=boost::bind(notify_, &signal, _1);
		notify(10);
	}
	return 0;
}
