#include <cassert>
#include <vector>
#include <algorithm>
#include <functional> // std::greater, std::bind2nd
#include <iostream>

// http://stackoverflow.com/questions/11514688/passing-const-pointer-by-reference

void fct_unsafe(const int*& n)
{
}

void fct_safe(int* const& n)
{
}

class Base
{
    std::vector<int> m_v;
    int m_a[5];
    int* m_ptr;
    
public:
    Base():
        m_v(5),
        m_ptr(new int(0))
    {
    }

    void set(int i, int n) const
    {
        // Constant member functions are not allowed to 
        // change member variables

        // m_v[i]=n; //nok
        // m_a[i]=n; //nok
    }

    int* get() const
    {
        return m_ptr;
    }

    void do_() const
    {
        std::find(m_v.begin(), m_v.end(), 5);
        std::find_if(m_v.begin(), m_v.end(), std::bind2nd(std::greater<int>(), 5));
    }
};

class base
{
    int m_n;

public:
    const int& n() const { return m_n; }
    int& n() { return m_n; }
};

int main()
{
    {
        // const variable

        int const n=5;
        // or
        // const int n=5;

        // n=4; //nok
    }
    {
        // mutable pointer on const variable

        int const * p=new int(5);
        //or
        //const int * p=new int(5);

        //*p=9; //nok

        p++; p--;
        assert(*p == 5);
    }
    {
        // mutable pointer on const variable
        
        int a[]={ 0, 1, 2 };
        int const * p=a;

        p++;
        assert(*p == 1);

        //*p=9; //nok
    }
    {
        // const pointer on mutable variable

        int* const p=new int(5);

        *p=9;
        assert(*p == 9);

        //p++; //nok
    }
    {
        // const pointer on const variable

        int const * const p=new int(5);

        //*p=9; //nok
        //p++; //nok
    }
    {
        Base b;
        int* ptr=b.get();
        assert(*ptr==0);
        *ptr=9;
        assert(*ptr==9);
        assert(*b.get()==9);
        b.do_();
    }
    {
        int* n;
        //fct_unsafe(n); //error: not type-safe
        fct_safe(n);
    }
    {
        base b;
        b.n()=5;
        assert(b.n()==5);
    }

    return 0;
}
