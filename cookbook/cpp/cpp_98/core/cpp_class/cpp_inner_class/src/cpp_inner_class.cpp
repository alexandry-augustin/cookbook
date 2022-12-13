#include <cassert>

class A { };

// Member functions of the enclosing class have no special access
// to members of a nested class
class B
{
    int _n_00;
    class C { }; // inner class

protected:
    int _n_01;
    class D: public A { }; // inner class

public:
    int n_02;

    // Member functions of a nested class have no special access 
    // privileges to members of their enclosing classes.
    class E
    {
        int _n_00;

    protected:
        int _n_01;

    public: 
        int n_02;

        void f_00()
        {
            C c;
        }
    };
};

//https://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fcplr061.htm
// class A
// {
//     int x;
//     class B { };
//     class C
//     {
//         // The compiler cannot allow the following
//         // declaration because A::B is private:
//         B b;

//         int y;
//         void f(A* p, int i)
//         {
//             // The compiler cannot allow the following
//             // statement because A::x is private:
//             //   p->x = i;

//         }
//     };
//     void g(C* p)
//     {
//         // The compiler cannot allow the following
//         // statement because C::y is private:
//         //   int z = p->y;
//     }
// };

int main()
{
    {
        B b;
        B::E i;

        i.n_02 = 5;
        assert(i.n_02 == 5);
    }
    
    return 0;
}
