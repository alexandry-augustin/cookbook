#include <iostream>
#include <typeinfo> //std::bad_cast

//dynamic_cast: downcasts at runtime
//  applies only to polymorphic types (public inheritance, and at least 1 virtual fct in the base)
//  do not const (const_cast) or volatile, or unrelated types (reinterpret_cast)

class base
{
public:
    //Since RTTI is included in the virtual method table
    //there should be at least one virtual function.
    virtual void dummy() {};
};

class sub: public base
{
public:

    void method_specific_to_sub() {};
};

void fct_ptr(base* b)
{
    sub* s=dynamic_cast<sub*>(b);

    //if(s!=NULL)
    //or
    if(s!=0)
        s->method_specific_to_sub();
    else
        std::cerr<<"[fct_ptr] [NULL] This object is not of type sub."<<std::endl;
} 

void fct_ref(base& b)
{
    try
    {
        sub& s=dynamic_cast<sub&>(b);
        s.method_specific_to_sub();
    }
    catch (const std::bad_cast& e)
    {
        std::cerr<<"[fct_ref] ["<<e.what()<<"] This object is not of type sub."<<std::endl;
    }
}

int main()
{
    {
        //NOK
        base b_ref;
        fct_ref(b_ref);
    }
    {
        //OK
        sub s_ref;
        fct_ref(s_ref);
    }
    {
        //OK
        sub* s_ptr=new sub();
        fct_ptr(s_ptr);
        delete s_ptr;
    }
    {
        //NOK
        base* b_ptr=new base();
        fct_ptr(b_ptr);
        delete b_ptr;
    }
    return 0;
}
