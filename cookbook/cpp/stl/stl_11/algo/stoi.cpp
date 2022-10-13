#include <string>
#include <cassert>

int main(int argc, char* argv[])
{
    std::string s = "25";
    int n = std::stoi(s);
    assert(n == 25);

    return 0;
}
