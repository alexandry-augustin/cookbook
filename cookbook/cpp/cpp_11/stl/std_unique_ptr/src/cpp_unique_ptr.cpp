#include <assert.h>
#include <memory>

namespace std_
{
// std::make_unique is no available in c++11: http://herbsutter.com/gotw/_102/
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
} //ns

int main()
{
	{
		std::unique_ptr<int> ptr;
		ptr=std_::make_unique<int>(5);
		assert(*ptr==5);
	}
	return 0;
}
