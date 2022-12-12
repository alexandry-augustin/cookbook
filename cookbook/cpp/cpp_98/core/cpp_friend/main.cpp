#include <iostream>
#include <string>
#include <sstream>

class sub;

class base
{
    friend class sub;
    friend std::string to_string(const base& b);

    int _n;
public:
    base(int n): _n(n) {}   
};

class sub 
{
    base _b;
public:
    sub(int n): _b(n) {}

    void fct(const base& b)
    {
        std::cout<<b._n<<std::endl;
    }
    int get() const
    {
        return _b._n;
    }
};

std::string to_string(const base& b)
{
    std::stringstream ss;
    ss<<b._n;
    return ss.str(); 
}

int main()
{
    {
        sub s(1);
        base b(2);
        std::cout<<s.get()<<std::endl;
        s.fct(b);
        std::cout<<to_string(b)<<std::endl;
    }

    return 0;
}
