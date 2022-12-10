#include <iostream>
#include <cassert>
#include <vector>
#include <iterator> //back_inserter

//effective stl Item 36 p130

template< typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator copy_if(InputIterator begin, InputIterator end, OutputIterator dest_begin, Predicate pred)
{
	while(begin!=end)
	{
		if(pred(*begin))
			*dest_begin++=*begin;
		++begin;
	}
	return dest_begin;
};

struct Base
{
	int _n;
	Base(int n): _n(n) { }
};

struct IsOdd
{
	bool operator()(int i) const
	{
		return (i%2!=0);
	}
};

struct BaseIsOdd:
	public std::unary_function<Base*, bool>
{
	bool operator()(Base* b) const
	{
		return (b->_n%2!=0);
	}
};

int main()
{
	std::vector<int> v, w;
	std::vector<Base*> x, y, z;
	std::vector<Base*>* u=new std::vector<Base*>();
	for(int i=0; i<10; ++i) v.push_back(i);
	for(int i=0; i<10; ++i) x.push_back(new Base(i));
	
	copy_if(v.begin(), v.end(), back_inserter(w), IsOdd());
	copy_if(x.begin(), x.end(), back_inserter(y), BaseIsOdd());
	copy_if(x.begin(), x.end(), back_inserter(*u), BaseIsOdd());
	copy_if(x.begin(), x.end(), back_inserter(z), std::not1(BaseIsOdd()));
	
	for(std::vector<int>::iterator it=w.begin(); it!=w.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	for(std::vector<Base*>::iterator it=y.begin(); it!=y.end(); ++it)
		std::cout<<(*it)->_n<<" ";
	std::cout<<std::endl;
	for(std::vector<Base*>::iterator it=z.begin(); it!=z.end(); ++it)
		std::cout<<(*it)->_n<<" ";
	std::cout<<std::endl;
	for(std::vector<Base*>::iterator it=u->begin(); it!=u->end(); ++it)
		std::cout<<(*it)->_n<<" ";
	std::cout<<std::endl;
	
	//std::vector<int>::back_insert_iterator it=copy_if(v.begin(), v.end(), back_inserter(w), IsOdd());
	
	return 0;
}
