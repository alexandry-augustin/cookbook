#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cassert>
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

void completion_handler()
{
	std::cout<<"finished!"<<std::endl;
}

struct notify_on_completion
{
	typedef void result_type;

	template <typename InputIt>
	void operator()(InputIt first, InputIt last)
	{
		completion_handler();
	}
};

template <typename T>
struct combiner
{
	typedef T result_type;

	template <typename InputIt>
	T operator()(InputIt first, InputIt last)
	{
		if(first==last)		//if signal.num_slots()==0
			return T();	//default-constructed value

		static int i=0;
		while(first!=last)
		{
			std::cout<<"handler"<<i++<<" ["<<(*first)<<"]"<<std::endl;
			++first;
		}

		completion_handler();

		return 2;
	}
};

int handler0(int n)
{
	return 10;
}

int handler1(int n)
{
	return 20;
}

class base
{
public:
	class notify_on_completion
	{
		base& _b;
	public:
		typedef void result_type;

		notify_on_completion(base& b): _b(b) { }

		template <typename InputIt>
		void operator()(InputIt first, InputIt last)
		{
			_b.handle_completed();
		}
	};
private:
	notify_on_completion _inner;
public:
	base(): _inner(*this) { }
	void handle_process()
	{
		std::cout<<"processing"<<std::endl;
	}
	void handle_completed()
	{
		std::cout<<"completed"<<std::endl;
	}
};

int main()
{
	{
		boost::signal<int (int), notify_on_completion> sig;
		sig.connect(handler0);
		sig.connect(handler1);
		sig(5);
	}
	{
		base b;
		boost::signal<void (void), base::notify_on_completion> sig;
//		sig.connect(boost::bind(&base::handle_process, &b));
	//	sig();
	}
	{
		// return value
		boost::signal<int (int), combiner<int> > sig;
		sig.connect(handler0);
		sig.connect(handler1);
		assert(sig(5)==2); //default: return the return value of the last handler called
	}
	
	return 0;
}