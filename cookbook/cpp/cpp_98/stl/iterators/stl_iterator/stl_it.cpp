#include <cassert>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

class Base
{
	int m_n;

public:
	Base(int n=0):
		m_n(n)
	{
	}

	int getN() const { return m_n; }
	void setN(int n) { m_n=n; }

//	Base operator*(const Base& b) const { return Base(m_n*b.m_n); }
//	Base operator+(const Base& b) const { return Base(m_n+b.m_n); }
//	Base operator++() { m_n++; return Base(m_n); } //check
//	Base& operator++(int) { m_n++; return (*this);} //check
//	Base operator-(const Base& b) const { return Base(m_n-b.m_n); }
//	Base& operator=(const Base& b) { m_n=b.m_n; return (*this); }
//	Base& operator+=(const Base& b) { m_n=m_n+b.m_n; return (*this); }
//	Base& operator*=(const Base& b) { m_n=m_n*b.m_n; return (*this); }
//	Base operator-() const { return Base(-m_n); } 
//	operator int() { return m_n; }
};

template<typename T>
class BaseList
{
	std::list<T> m_list;

public:
	typedef typename std::list<T>::iterator		iterator;
	typedef typename std::list<T>::const_iterator	const_iterator;
	typedef typename std::list<T>::size_type	size_type;
	typedef typename std::list<T>::difference_type	difference_type;
	typedef typename std::list<T>::pointer		pointer;
	typedef typename std::list<T>::reference	reference;
	typedef typename std::list<T>::const_pointer	const_pointer;
	typedef typename std::list<T>::const_reference	const_reference;

	BaseList()
	{
	}

	BaseList::size_type size() { return m_list.size(); }
	bool empty() { return m_list.empty(); }

	void pop_back() { m_list.pop_back(); }
	void pop_front() { m_list.pop_front(); }
	void push_front(const T& item) { m_list.push_front(item); }
	void push_back(const T& item) { m_list.push_back(item); }
	bool delete_item(T* item);

	//calling these functions on an empty container causes undefined behavior
	T& back() { return m_list.back(); }
	T& front() { return m_list.front(); }

	BaseList::iterator erase() { return m_list.erase(); }
	BaseList::iterator begin() { return m_list.begin(); }
	BaseList::iterator begin() const { return m_list.begin(); }
	BaseList::iterator end() { return m_list.end(); }
	BaseList::iterator end() const { return m_list.end(); }
};

template <typename T>
class BaseVector
{
	std::vector<T> m_vector;

public:
	typedef typename std::vector<T>::const_iterator		const_iterator;
	typedef typename std::vector<T>::iterator		iterator;
	typedef typename std::vector<T>::size_type		size_type;
	typedef typename std::vector<T>::difference_type	difference_type;
	typedef typename std::vector<T>::pointer		pointer;
	typedef typename std::vector<T>::reference		reference;
	typedef typename std::vector<T>::const_pointer		const_pointer;
	typedef typename std::vector<T>::const_reference	const_reference;

	BaseVector()
	{
	}
	BaseVector(T* begin, T* end):
		m_vector(begin, end)
	{
	}

	BaseVector::size_type size() { return m_vector.size(); }
	bool empty() { return m_vector.empty(); }
	void push_back(const T& item) { m_vector.push_back(item); }
	void push_front(const T& item) { m_vector.push_front(item); }
	void pop_back() { m_vector.pop_back(); }
	void pop_front() { m_vector.pop_front(); }

	BaseVector::const_iterator begin() const { return m_vector.begin(); }
	BaseVector::iterator begin() { return m_vector.begin(); }
	BaseVector::const_iterator end() const { return m_vector.end(); }
	BaseVector::iterator end() { return m_vector.end(); }

};

int __main()
{
//	Base* a[]={ new Base(9), new Base(2), new Base(0), new Base(4), new Base(1) };
//	BaseVector<Base*> base_vector(a, a+5);
	BaseVector<Base*> base_vector;
	BaseList<Base*> base_list;
	for(int i=0; i<10; ++i) base_vector.push_back(new Base(i));
	for(int i=0; i<10; ++i) base_list.push_back(new Base(i));
	
//	BaseVector<Base*>::difference_type n=std::distance(base_vector.begin(), base_vector.end());
//	assert(n==5);
//	
	std::sort(base_vector.begin(), base_vector.end());
	
	for(BaseVector<Base*>::const_iterator it=base_vector.begin(); it!=base_vector.end(); ++it)
		std::cout<<(*it)->getN()<<" ";
	std::cout<<std::endl;
	
	std::copy(base_vector.begin(), base_vector.end(), std::ostream_iterator<Base*>(std::cout, " "));
	std::cout<<std::endl;
	
	{
		BaseVector<Base*>::const_iterator it=base_vector.begin();
		BaseVector<Base*>::const_iterator const_it=base_vector.begin();
		std::advance(const_it, 2);
		//assert((*const_it)->getN()==2);
	}
	
	return 0;
}

	//	for(base_vector.get()::const_iterator it=base_vector.begin(); it!=base_vector.end(); ++it)
	//		std::cout<<*it<<" ";
	//	std::cout<<std::endl;
