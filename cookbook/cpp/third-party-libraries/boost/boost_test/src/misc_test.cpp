#define BOOST_TEST_MODULE misc_test
#include <boost/test/unit_test.hpp>
//---------------------------------------------------------
int add(int i, int j) { return i+j; }
//---------------------------------------------------------
BOOST_AUTO_TEST_CASE(add_test)
{
	if(add(2, 2)!=4)
		BOOST_ERROR("ouch...");
}
