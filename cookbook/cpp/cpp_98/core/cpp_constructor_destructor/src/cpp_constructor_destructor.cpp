#include <iostream>

// According to the C++ standard, the copy constructor for base must have one of the following signatures:
//  base(const base& other);
//  base(base& other);
//  base(volatile const base& other);
//  base(volatile base& other);
// 
// Note that none of the following constructors, despite the fact that they could do the same thing as a copy constructor, are not copy constructors:
//  base(base* other);
//  base(const base* other);
//
//  base(base other); //infinite loop

struct Base
{
    int a;
    
    Base()
    {
        std::cout<<"Base C"<<std::endl;
        a=5;
    }

    class Nest
    {
        int b;
    public:
        Nest()
        {
            std::cout<<"Nest C"<<std::endl;
        }
    };
    //~Base(){try{}catch{}}
};

struct Sub: public Base
{
    Sub() { std::cout<<"Sub C"<<std::endl; }
};

class base_01
{
    base_01(int n)
    {
    }
};

void f(const base_01& b) { }

int main()
{
    {
        Sub s;
        Sub q(s); //default copy constructor
        q.a=6;
        q=s;
    }
    {
        //f(0); //nok
    }

    return 0;
}
