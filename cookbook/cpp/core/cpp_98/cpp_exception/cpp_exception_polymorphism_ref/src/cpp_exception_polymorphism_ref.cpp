#include <cassert>

class base_00 {};
class base_01: public base_00 {};
class base_02: public base_01 {};

class base_03
{
public:
	base_03() {}
	base_03(const base_00&) {}
};

int main()
{
	{
		try
		{
			throw base_00();
		}
		catch(const base_00& b)
		{
		}
		catch(const base_01& b)
		{
			assert(false);
		}
		catch(const base_02& b)
		{
			assert(false);
		}
	}
	{
		//re-order the catch(s) in reverse order for this to work
		try
		{
			throw base_02();
		}
		catch(const base_00& b)
		{
		}
		catch(const base_01& b)
		{
			assert(false);
		}
		catch(const base_02& b)
		{
			assert(false);
		}
	}
	{
		try
		{
			throw base_03();
		}
		catch(const base_00& b) //no use of converting constructor
		{
			assert(false);
		}
		catch(const base_03& b)
		{
		}
	}
	return 0;
}
