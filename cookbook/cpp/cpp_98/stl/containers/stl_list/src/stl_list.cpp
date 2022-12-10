#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <cassert>

class list
{
public:
	list();
};

template<typename T>
bool find(std::list<T>& l, T value)
{
	typename std::list<T>::iterator it=std::find(l.begin(), l.end(), value);
	if(it==l.end())
		return false;
	else
		return true;
}

template<typename T>
void set(std::list<T>& l, int i, T value)
{
	if(l.size()<=i)
		assert(false);
	
	typename std::list<T>::iterator it=l.begin();
	std::advance(it, i);
	*it=value;
}

//get the ith element of a list
template<typename T>
T get_(std::list<T> l, int i)
{
	if(l.size()<=i)
		assert(false);
	
	typename std::list<T>::iterator it=l.begin();
	std::advance(it, i);
	
	return *it;
}

//get the ith element of a list
template<typename T>
T get(std::list<T> l, int i)
{
	if(l.size()<=i)
		assert(false);
	
	T ret;
	int j=0;
	for(typename std::list<T>::iterator it=l.begin(); it!=l.end(); ++it) 
		if((j++)==i)
		{
			ret=*it;
			break;
		}
	
	return ret;
}

//list traversal
template<typename T>
std::string traverse(std::list<T> l)
{
	std::stringstream ss;
	
	for(typename std::list<T>::iterator i=l.begin(); i!=l.end(); ++i) 
		ss<<*i<<" ";
	
	return ss.str();
}

//doubly-linked lists
int main()
{
	std::list<int> l;
	
	l.push_back(1);
	l.push_front(3);
	
	std::list<int>::iterator i; //bidirectional iterator
	i=l.begin();
	++i;
	l.insert(i,2);
	--i;
	
	/* doesn't work !!
	//for(int j=0; j<2; ++j)
		++i;
		++i;
	std::cout<<*i;*/
	
	std::cout<<traverse(l)<<std::endl;
	
	std::cout<<get(l, 1)<<std::endl;
	set(l, 1, 5);
	std::cout<<get_(l, 1)<<std::endl;
	std::cout<<find(l, 5)<<std::endl;
	
	l.pop_front();
	l.pop_back();
	l.size();
	
	{
		//erase
		std::list<int> l;
		std::list<int>::iterator it;

		for(int i=0; i<10; ++i)
			l.push_back(i);

		it=l.begin();
		std::advance(it, 5);
		l.erase(it, l.end());

		assert(l.size()==5);

		it=l.begin();
		assert(*it==0);
		std::advance(it, 4);
		assert(*it==4);

		it=l.begin();
		l.erase(it);
		assert(l.size()==4);
	}
    {
        //constructor
        std::list<int> l_00(4, 100); // four ints with value 100
        std::list<std::string> l_01(1, std::string("tmp"));
    }
	return 0;
}
