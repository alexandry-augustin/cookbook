#include <cassert>
#include <iostream>
#include <string>

//static_cast: type conversions at compile time

class Base
{
public:
    virtual int get()
    {
        return 0;
    }
};

class Sub: public Base
{
public:
    /*virtual*/ int get()
    {
        return 1;
    }
};

int main()
{
    {   
        int n=static_cast<int>(float(5.8));
        assert(n==5);
    }
    {
        void* p=static_cast<void*>(new int(9));
        assert((*static_cast<int*>(p))==9);
        // delete m;
    }
    {
        Base* p=new Sub();
        assert(static_cast<Sub*>(p)->get()==1);
        // delete s;
    }

    return 0;
}
