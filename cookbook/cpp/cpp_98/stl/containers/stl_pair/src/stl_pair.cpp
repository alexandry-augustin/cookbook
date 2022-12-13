#include <cassert>
#include <utility> // for std::pair()

int main()
{
    {
        std::pair<int, int> p(3, 5);

        assert(p.first == 3);
        assert(p.second == 5);
    }
    {
        std::pair<int, int> p;
        p.first = 3;
        p.second = 5;

        assert(p.first == 3);
        assert(p.second == 5);
    }
    {
        std::pair<int, int> p;
        p=std::make_pair(3, 5);

        assert(p.first == 3);
        assert(p.second == 5);
    }

    return 0;
}
