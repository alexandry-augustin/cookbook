#include <iostream>
#include <string>
#include <boost/signals2.hpp>

struct base
{
	void operator()() const
	{
		this->print("Hello World");
	}

    void print(const std::string& msg) const
    {
		std::cout << msg << std::endl;
    }
};

int main()
{
	{
		boost::signals2::signal<void ()> sig;

		base b;
		sig.connect(b);

		sig();
	}
	{
		boost::signals2::signal<void (const std::string&)> sig;

		base b;
		sig.connect(boost::bind(&base::print, b, boost::placeholders::_1));

		sig("Hello");
		sig("World");
	}

	return 0;
}
