#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

template <typename T>
class Item
{
	T _value;
public:
	explicit Item(T value=0): _value(value) { }
	T get() const { return _value; }
	void set(T value) { _value=value; }
};

template <typename T>
struct ContainerTraits
{
	typedef typename T::type_t	type_t;
	typedef typename T::ptr_t	ptr_t;
};

template <typename T>
class Container
{
	T	_container[255]; 
	int	_size;
public:
	typedef T	type_t;
	typedef T*	ptr_t;

	Container(): _size(0) { }
	void insert(T t) { _container[_size++]=t; }
	T get(int index) const { assert(index<_size); return _container[index]; }
	void set(T t, int index) const { assert(index<_size); _container[index]=t; }
	int size() const { return _size; }
};

namespace algo
{

template <typename T>
typename T::type_t sum(T t, int size)
{
	typename T::type_t res=typename T::type_t(0);
	for(int i=0; i<size; ++i)
		res.set(res.get()+t.get(i).get());
	return res;
}
template <typename T>
typename ContainerTraits<T>::type_t mult(T t, int size)
{
	typename ContainerTraits<T>::type_t res=typename ContainerTraits<T>::type_t(1);
	for(int i=0; i<size; ++i)
		res.set(res.get()*t.get(i).get());
	return res;
}

}; //ns

int main()
{
	{
		Container<Item<int> > c;
		c.insert(Item<int>(5));
		c.insert(Item<int>(3));

		assert(algo::sum(c, c.size()).get()==8);
		assert(algo::mult(c, c.size()).get()==15);
	}
	return 0;
}
