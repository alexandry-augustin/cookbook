#include <cassert>
#include <utility> // for std::pair()

class base
{
protected:
    int m_a, m_b;

public:
    base(int a=0, int b=0); //defaults values in declaration, not implementation
    std::pair<int, int> get() const;
};

base::base(int a, int b): m_a(a), m_b(b) { } //initialisation list in implementation, not declaration

std::pair<int, int> base::get() const
{
    return std::pair<int, int>(m_a, m_b);
}

class sub: public base
{
    int m_c;

public:
    sub()//: m_a(5) //nok
    {
        m_a=5; //ok
    }
};

int main()
{
    {
        base b; // calls default constructor
        assert(b.get().first == 0);
        assert(b.get().second == 0);
    }
    {
        sub s;
        assert(s.get().first == 5);
        assert(s.get().second == 0);
    }

    return 0;
}
