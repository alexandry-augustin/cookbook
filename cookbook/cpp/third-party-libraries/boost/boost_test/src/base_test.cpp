//http://www.boost.org/doc/libs/1_39_0/libs/test/doc/html/utf/tutorials.html
//http://www.ibm.com/developerworks/aix/library/au-ctools1_boost/

#include "base.h"
#include <list>
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE base_test
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <boost/test/floating_point_comparison.hpp> //BOOST_*_CLOSE_FRACTION
//---------------------------------------------------------
//throwing is suitable when writing an explicit test program,
//and the error would be so severe as to make further testing impractical. 

//exceptions will be caught and reported by the Unit Test Framework.
//the error message displayed when the exception is caught will be 
//most meaningful if the exception is derived from std::exception, or is a char* or std::string.
//---------------------------------------------------------
// 	use warnings when validate aspects less important then correctness: performance, portability, usability ...

//	need to set the log level by:
//	* passing --log-level=all as an option the the test executable
//	* setting the environment variable BOOST_TEST_LOG_LEVEL to all.

//	boost/test/detail/log_level.hpp
//	log_level=
//	invalid_log_level        
//	log_successful_tests     
//	log_test_units           
//	log_messages             
//	log_warnings             
//	log_all_errors           // reported by unit test macros
//	log_cpp_exception_errors // uncaught C++ exceptions
//	log_system_errors        // including timeouts, signals, traps
//	log_fatal_errors         // including unit test macros or
//	// fatal system errors
//	log_nothing              
//---------------------------------------------------------
BOOST_AUTO_TEST_SUITE(base_test) //name of the test suite
//---------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_00)
{
	base b(6);

	BOOST_CHECK(b.get_n()==6); 	//continue on error
	BOOST_REQUIRE(b.get_n()==6); 	//throw on error
	BOOST_WARN(b.get_n()==8); 	

	if(b.get_n()!=6)
		BOOST_ERROR("ouch..."); //continues on error
	if(b.get_n()!=6)
		BOOST_FAIL("ouch...");	//throws on error

	BOOST_CHECK_EQUAL(b.get_n(), 6);	//continue on error
	BOOST_WARN_EQUAL(b.get_n(), 6);

	BOOST_CHECK_MESSAGE(b.get_n()==6, "get_n() result: "<<b.get_n());
}
//---------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_01)
{
	base b(0);

	boost::test_tools::output_test_stream output("run.log", true);
	//output<<predefined_user_func();
	BOOST_CHECK(output.match_pattern());

	//The left and right values in the macro must be of the same type: float or double
	float f_00=99.0002;
	float f_01=99.0001;
	//BOOST_WARN_CLOSE_FRACTION
	//BOOST_REQUIRE_CLOSE_FRACTION
	BOOST_CHECK_CLOSE_FRACTION(f_00, f_01, 0.0001);
}
//---------------------------------------------------------
boost::test_tools::predicate_result validate_list_00(const std::list<int>& l, int n)
{ 
	for(std::list<int>::const_iterator it=l.begin(); it!=l.end(); ++it) 
		if(*it!=n)
			return false; //predicate_result has an implicit bool constructor 
	return true;
}
//---------------------------------------------------------
bool validate_list_01(const std::list<int>& l)
{ 
	for(std::list<int>::const_iterator it=l.begin(); it!=l.end(); ++it) 
		if(*it!=0)
			return false;
	return true;
}
//---------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_02)
{
	base b(0);
	const std::list<int>& list1=b.get_list();
	BOOST_CHECK(validate_list_00(list1, b.get_n()));
	//BOOST_CHECK_PREDICATE(validate_list_01, l);
}
//---------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()
