#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <boost/any.hpp> 

struct Formattable
{
	virtual void str(std::ostream& o, boost::any& any) const=0;
	virtual Formattable* clone()=0;
};

template <typename T>
struct base: public Formattable
{
public:
	/*virtual*/ void str(std::ostream& o, boost::any& any) const
	{
		o<<*boost::any_cast<T>(&any);
	}

	/*virtual*/ Formattable* clone()
	{
		return new base<T>();
	}

	void str() const
	{
		std::cout<<"[base::str]"<<std::endl;
	}
};

class formattable_any
{
	boost::any m_any;
	Formattable* m_formattable;

public:
	formattable_any()
		: m_any(NULL) 
	{
	}

	template <typename T>
	formattable_any(const T& any)
		: m_any(any), m_formattable(new base<T>)
	{
	}

	template <typename T>
	formattable_any& operator=(const T& any)
	{
		formattable_any(any).swap(*this);
		return *this;
	}
};

int main()
{
	std::vector<formattable_any> v;

	v.push_back(str);
	v.push_back(112);
	v.push_back(new base());

	std::cout<<v[0]<<std::endl;
	std::cout<<v[1]<<std::endl;
	std::cout<<v[2]<<std::endl;

	return 0;
}
