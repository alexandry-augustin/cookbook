#include <cassert>
#include <iostream>
#include <limits>

int main()
{
	//std::size_t <cstddef> same as size_t <stddef.h>

	//std::allocator<T>::size_type
	//container::size_type (container dependent)
	//all std containers use size_t as the size_type but other library vendors choose a type that they find appropriate for their container.
	//Qt: the size_type of Qt containers is version dependent in Qt3 it was unsigned int and in Qt4 they changed it to int.

	const int min_int=std::numeric_limits<int>::min();
	const int max_int=std::numeric_limits<int>::max();

	return 0;
}
