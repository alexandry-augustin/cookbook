#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

class base
{
    int _n;
public:
    base(int n): _n(n) { }
    void set(int n) { _n=n; }
    int get() const { return _n; }
    void add() const
    {
        //non-const -> const
        const_cast<base*>(this)->set(get()+1);
        //or
        //const_cast<base*>(this)->_n++;

        //using reference
        const_cast<base&>(*this).set(get());
    }
    void sub()
    {
        //const -> non-const
        set(const_cast<base*>(this)->get()-1);

        //using reference
        set(const_cast<base&>(*this).get());
    }
};

int main()
{
    {
        base b(5);
        b.add();
        b.sub();
        assert(b.get()==5);
    }
    
    return 0;
}
