#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

class Base
{
	int _n;
public:
	Base(int n=0): _n(n)
	{
	}
	int& get()
	{
		return _n;
	}
};

class BaseIterator: public std::iterator<std::input_iterator_tag, Base>
{
	Base* p;
public:
	BaseIterator(Base* x): p(x)
	{
	}
	BaseIterator(const BaseIterator& mit): p(mit.p)
	{
	}
	BaseIterator& operator++()
	{
		++p;
		return *this;
	}
	BaseIterator operator++(int)
	{
		BaseIterator tmp(*this);
		operator++();
	
		return tmp;
	}
	bool operator==(const BaseIterator& rhs)
	{
		return p==rhs.p;
	}
	bool operator!=(const BaseIterator& rhs)
	{
		return p!=rhs.p;
	}
	Base& operator*()
	{
		return *p;
	}
};

template <typename T>
class BaseContainer
{
public:
	typedef int size_type;
	
	class iterator
	{
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i=*this; ptr_++; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_!=rhs.ptr_; }
	private:
		pointer ptr_;
	};
	class const_iterator
	{
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;
		const_iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i=*this; ptr_++; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		const reference operator*() { return *ptr_; }
		const pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_!=rhs.ptr_; }
	private:
		pointer ptr_;
	};
	BaseContainer(size_type size)
		: size_(size) 
	{
		data_=new T[size_];
	}
	size_type size() const
	{
		return size_;
	}
	T& operator[](size_type index)
	{
		assert(index<size_);
		return data_[index];
	}
	const T& operator[](size_type index) const
	{
		assert(index<size_);
		return data_[index];
	}
	iterator begin()
	{
		return iterator(data_);
	}
	iterator end()
	{
		return iterator(data_+size_);
	}
	const_iterator begin() const
	{
		return const_iterator(data_);
	}
	const_iterator end() const
	{
		return const_iterator(data_+size_);
	}
private:
	T* data_;
	size_type size_;
};

int main()
{
	{
		//int a[]={ 2, 3, 4 };
		BaseContainer<int> v(3);
		v[0]=2;
		v[1]=3;
		v[2]=4;
		
		for(BaseContainer<int>::iterator it=v.begin(); it!=v.end(); ++it)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		
		std::vector<int> vec(3);
		vec[0]=2;
		vec[1]=3;
		vec[2]=4;
		std::copy(v.begin(), v.end(), std::back_inserter(vec));
		
		for(std::vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		
		Base b(5), c(9);
		Base a[2];
		a[0]=b;
		a[1]=c;
		BaseIterator beginning(a);
		BaseIterator end(a+2);
		for(BaseIterator it=beginning; it!=end; it++)
			std::cout<<(*it).get()<<" ";
		std::cout<<std::endl;
	}
	return 0;
}
