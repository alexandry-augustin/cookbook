#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>

/*class base_00
{
public:
	//base_00();
	class const_iterator
	{
	public:
		const_iterator() : p_(0)
		{
		}
		const_iterator(const char *p) : p_(p)
		{
		}
		const_iterator &operator ++ ()
		{
			p_ += reinterpret_cast<const T_msg *>(p_)->getLength();
			return(*this);
		}
		bool operator == (const const_iterator &i)
		{
			return(p_ == i.p_);
		}
		bool operator != (const const_iterator &i)
		{
			return(p_ != i.p_);
		}
		const T_msg & operator *() const
		{
			return(* reinterpret_cast<const T_msg *>(p_));
		}
		const char *getPtr()
		{
			return(p_);
		}
	private:
		const char *p_;
	};

	const char *getStartPtr() const
	{
	return(data_);
	}

	char *getEndPtr()
	{
	return(data_ + length_);
	}

	const char *getEndPtr() const
	{
	return(data_ + length_);
	}

	const_iterator begin() const
	{
	return(const_iterator(getStartPtr()));
	}

	const_iterator end() const
	{
	return(const_iterator(getEndPtr()));
	}

	size_t length_;            // how long the data is
	char data_[DATA_SIZE];     // the data starts here
};
};*/

//safe ?! version
template <typename T, typename It>
void advance(const T& v, It& it, int n)
{
  int count=0;
  if(n>0)
  {
      while(true)
      {
        if(count>=n)
          break;
        if(it==v.end())
          break;
        ++count;
        ++it;
      }
  }
  else
  {
      while(true)
      {
        if(count<=n)
          break;
        if(it==v.begin())
          break;
        --count;
        --it;
      }
  }
}

int main()
{
	{
		int a[]={ 0, 1, 2, 3 };
		std::vector<int> v(a, a+4);
		std::vector<int>::iterator it_00;
		
		it_00=v.begin();
		std::advance(it_00, 2);
		assert(*it_00==2);

		std::advance(it_00, 99); //undefined behavior
		assert(it_00>v.end());
	}
	return 0;
}
