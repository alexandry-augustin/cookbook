#include <cassert>
#include <iostream>

void f()
{
    throw 56;
    assert(false); //never executed
}

struct base_00
{
    ~base_00()
    {
        throw 1;
    }
};

class base_01
{
    int _n;
public:
    base_01()
    {
    }
    ~base_01()
    {
        std::cout<<"destroyed"<<std::endl;
    }
    void throw_()
    {
        throw 0;
    }
    const int& n() const
    {
        return _n;
    }
    int& n()
    {
        return _n;
    }
};

int main()
{
    {
        try
        {
            f();
            assert(false); //never executed
        }
        catch(int e)
        {
            std::cerr<<"int exception: "<<e<<std::endl;
        }
        catch(...)
        {
            std::cerr<<"other exception"<<std::endl;
        }
    }
    {
        try
        {
            base_00 base;
        }
        catch(...)
        {
            std::cerr<<"ok"<<std::endl;
        }
    
        //the below will terminate the application
        /*try
        {
            base_00 base;
            throw 2;
        }
        catch(...)
        {
            assert(false); //never reached
        }*/
    }
    {
        base_01*    b_00=new base_01();
        base_01     b_01;
        try
        {
            b_01.throw_();
            //b_00->throw_();
        }
        catch(int n)
        {
            std::cerr<<"caught"<<std::endl;
        }
    }
    {
        try
        {
            try
            {
                throw int(5);
            }
            catch(int n)
            {
                throw n+1;
            }
        }
        catch(int n)
        {
            assert(n==6);
        }   
    }

    return 0;
}
