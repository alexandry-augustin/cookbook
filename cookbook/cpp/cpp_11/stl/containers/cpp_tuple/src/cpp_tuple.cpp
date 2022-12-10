#include <cassert>
#include <tuple>

int main()
{
	{
		std::tuple<int, char> s=std::make_tuple(14, 'a');
		auto t=std::make_tuple("abc", 3.1, 14, 'a');
	}
	{
		std::tuple<int, char> t(2, 'a');

		std::get<0>(t)=1;
		assert(std::get<0>(t)==1);
		assert(t==std::make_tuple(1, 'a'));

		int myint; char mychar;
		std::tie(myint, mychar)=t; // unpack elements
	}
	{
		auto bar = std::make_tuple("test", 3.1, 14, 'y');

		std::get<2>(bar)=100; // access element

		int myint; char mychar;
		std::tie(std::ignore, std::ignore, myint, mychar)=bar;  // unpack (with ignore)
	}
	return 0;
}
