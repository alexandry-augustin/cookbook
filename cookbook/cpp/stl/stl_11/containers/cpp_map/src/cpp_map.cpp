#include <vector>
#include <list>
#include <string>
#include <map>

int main()
{
	std::map<std::string, std::vector<int> > m {
		{"a", {2, 2, 1, 2, 2, 2, 1}},
		{"b", {2, 1, 2, 2, 1, 2, 2}},
		{"c", {3, 2, 2, 3, 2}}
	};
}
