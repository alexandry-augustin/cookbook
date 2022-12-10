#include <iostream>
#include <cassert>
#include <map>
#include <string>
#include <sstream>

enum One {
    A_,
    B_
};

enum Two {
    //B_, //nok
    C_,
};

struct A
{
    enum Enum
    {
        ONE=1,
        TWO=2
    };
    static std::map<int, std::string> str; // int instead of A::Enum allows for A::str[1]
    static void init()
    {
        A::str[A::ONE]="one";
        A::str[A::TWO]="two";
    }
};
std::map<int, std::string> A::str;

struct B
{
    enum Enum
    {
        ONE=1,
        TWO=2
    };
};

enum N
{
    ZERO_   =0,
    ONE_    =1,
    TWO_    =2
};

struct Base
{
    N& n;   
    Base(N& n_):
        n(n_)
    {
    }
};

std::map<N, std::string> m;

//typedef typename ZERO_ zero; //not a type

std::string str_enum(N n)
{
    return m[n];
}

std::string str_enum_ref(N& n)
{
    return m[n];
}

std::string str_int(int n)
{
    std::stringstream ss;
    ss<<n;
    return ss.str();
}

std::string str_int_ptr(int* n)
{
    std::stringstream ss;
    ss<<*n;
    return ss.str();
}

int main()
{
    {
        A::Enum a;
        B::Enum b;
        int n;
    
        A::init();
        a=A::ONE;
        b=B::ONE;
        //a=B::ONE; //nok
        n=a;
    
        assert(n==1);
        n=b;
        assert(n==1);
        assert(A::str[A::ONE]=="one");
        assert(A::str[1]=="one");
    }
    m[ZERO_]="zero";
    m[ONE_]="one";
    m[TWO_]="two";
    {
        N n=ZERO_;
        int m=ZERO_;
    
        assert(n==m);
    
        //n=m;  //nok
        n=static_cast<N>(m);
    
        m=n;
        assert(m==n);
    
        assert(ZERO_==0);
    }
    {
        N n;
        N *p, *q;
        int* r;
    
        n=ZERO_;
        p=&n;
        //p=new ZERO_; //nok
        //p=&ZERO_; //nok
        q=reinterpret_cast<N*>(new int(2));
        r=reinterpret_cast<int*>(p);
    
        assert(*p==n);
        assert(*p==ZERO_);
    
        assert(str_enum(n)=="zero");
        assert(str_enum(*p)=="zero");
        assert(str_enum(static_cast<N>(0))=="zero");
        assert(str_enum(*q)=="two");
    
        assert(str_int(ZERO_)=="0");
        assert(str_int(*q)=="2");
        assert(str_int(*r)=="0");
    
        // TODO enum =>int*
//      assert(str_int_ptr(ZERO_)=="0");
        //assert(str_int_ptr(&n)=="0"); //nok
        //assert(str_int_ptr(static_cast<int>(n))=="0");
        assert(str_int_ptr(reinterpret_cast<int*>(q))=="2");
        assert(str_int_ptr(r)=="0");
    
        delete q;
    }
    {
        N n=ZERO_;
        //Base b(ZERO_); //nok
        Base b(n);
    }
    {
        const int x=5;
        int y=2;
        //enum temp { x, y }; //nok compile error ''x/y' redeclared as different kind of symbol'
    }
    
    return 0;
}
