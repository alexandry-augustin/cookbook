#include <iterator>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;



template<typename TypeT>
class PointerIterator :
	public std::iterator<random_access_iterator_tag, TypeT>
{
	protected:
		TypeT* m_pData;

	public:
		typedef random_access_iterator_tag iterator_category;
		typedef 
			typename iterator<random_access_iterator_tag, TypeT>::value_type
			value_type;
		typedef
			typename iterator<random_access_iterator_tag, TypeT>::difference_type
			difference_type;
		typedef 
			typename iterator<random_access_iterator_tag, TypeT>::reference
			reference;
		typedef 
			typename iterator<random_access_iterator_tag, TypeT>::pointer
			pointer;


		PointerIterator() : m_pData(NULL) {}


		template<typename T2>
			PointerIterator(const PointerIterator<T2>& r) : m_pData(&(*r)) {}

		PointerIterator(pointer pData) : m_pData(pData) {}

		template<typename T2>
			PointerIterator& operator=(const PointerIterator<T2>& r)
			{ m_pData = &(*r); return *this; }

		PointerIterator& operator++()
		{ ++m_pData; return *this; }

		PointerIterator& operator--()
		{ --m_pData; return *this; }

		PointerIterator operator++(int)
		{ return PointerIterator(m_pData++); }

		PointerIterator operator--(int)
		{ return PointerIterator(m_pData--); }

		PointerIterator operator+(const difference_type& n) const
		{ return PointerIterator(m_pData + n); }

		PointerIterator& operator+=(const difference_type& n)
		{ m_pData += n; return *this; }

		PointerIterator operator-(const difference_type& n) const
		{ return PointerIterator(pointer(m_pData - n)); }			

		PointerIterator& operator-=(const difference_type& n)
		{ m_pData -= n; return *this; }

		reference operator*() const
		{ return *m_pData; }

		pointer operator->() const
		{ return m_pData; }

		reference operator[](const difference_type& n) const
		{ return m_pData[n]; }


		template<typename T>
			friend bool operator==(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>
			friend bool operator!=(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>
			friend bool operator<(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>
			friend bool operator>(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>
			friend bool operator<=(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>
			friend bool operator>=(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>	
			friend typename PointerIterator<T>::difference_type operator+(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);

		template<typename T>	
			friend typename PointerIterator<T>::difference_type operator-(
					const PointerIterator<T>& r1,
					const PointerIterator<T>& r2);	
};

	template<typename T>
bool operator==(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData == r2.m_pData); }

	template<typename T>	
bool operator!=(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData != r2.m_pData); }

	template<typename T>
bool operator<(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData < r2.m_pData); }

	template<typename T>	
bool operator>(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData > r2.m_pData); }

	template<typename T>
bool operator<=(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData <= r2.m_pData); }

	template<typename T>	
bool operator>=(const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return (r1.m_pData >= r2.m_pData); }

	template<typename T>	
typename PointerIterator<T>::difference_type operator+(
		const PointerIterator<T>& r1,
		const PointerIterator<T>& r2)
{ return PointerIterator<T>(r1.m_pData + r2.m_pData); }

	template<typename T>	
typename PointerIterator<T>::difference_type operator-(
		const PointerIterator<T>& r1, const PointerIterator<T>& r2)
{ return r1.m_pData - r2.m_pData; }



template <typename T, size_t SizeT>
class StaticArray
{
	protected:
		T* m_pData;

	protected:
		void __allocate()
		{ m_pData = new T[SizeT]; if (!m_pData) throw runtime_error("!m_pData"); }
		void __free()
		{ if (m_pData) delete[] m_pData; }

	public:
		typedef PointerIterator<const T> const_iterator;
		typedef PointerIterator<T> iterator;

		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;

		StaticArray() : m_pData(NULL) { __allocate(); }
		StaticArray(const StaticArray& r) : m_pData(NULL)
	{
		__allocate();
		copy(r.m_pData, r.m_pData + SizeT, m_pData);
	}

		virtual ~StaticArray() { __free(); }

		const T& operator[](size_t ulInd) const
		{ return m_pData[ulInd]; }

		T& operator[](size_t ulInd)
		{ return m_pData[ulInd]; }

		const_iterator begin() const
		{ return const_iterator(m_pData); }

		const_iterator end() const
		{ return const_iterator(m_pData + SizeT); }

		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(end()); }

		const_reverse_iterator rend() const
		{ return const_reverse_iterator(begin()); }

		iterator begin()
		{ return iterator(m_pData); }

		iterator end()
		{ return iterator(m_pData + SizeT); }

		reverse_iterator rbegin()
		{ return reverse_iterator(end()); }

		reverse_iterator rend()
		{ return reverse_iterator(begin()); }

};



int main(void)
{
	StaticArray<float, 10> arr;
	for (size_t u = 0; u < 10; ++u)
		arr[u] = u + 1;

	StaticArray<float, 10>::iterator it = arr.begin();
	StaticArray<float, 10>::const_iterator cit;
	cit = it;

	StaticArray<float, 10>::reverse_iterator rit = arr.rbegin();
	StaticArray<float, 10>::reverse_iterator rEnd = arr.rend();
	StaticArray<float, 10>::const_reverse_iterator rcit = rit;
	StaticArray<float, 10>::const_reverse_iterator rcEnd;

	rcEnd = rEnd;

	cout << "Dist: " << distance(rcit, rcEnd) << endl;
	copy(rcit, rcEnd, ostream_iterator<float>(cout, "\t"));
	cout << endl;


	vector<float> vfVals;
	copy(arr.begin(), arr.end(), back_inserter(vfVals));	
	copy(vfVals.begin() + 4, vfVals.end(), ostream_iterator<float>(cout, "\t"));

	cout << endl;

	return 0;
}


