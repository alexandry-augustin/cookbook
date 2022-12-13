#include <cassert>

class base
{
    int m_n;

public:

    base(int n=0): m_n(n) { }
    
    base& add()
    {
        ++m_n;
        return (*this);
    }

    int get() const { return m_n; }
};

int main(int argc, char* argv[])
{
    {
        base b;
        b.add().add();
        assert(b.get() == 2);
    }
    {
        base b;
        assert(b.add().add().get() == 2);
    }
    
    return 0;
}
