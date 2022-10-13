//#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE MasterTestSuite
#include <boost/test/included/unit_test.hpp>

/*boost::test_suite* init_unit_test_suite(int argc, char* argv[])
{
	boost::test_suite* ts1 = BOOST_TEST_SUITE( "test_suite1" );
	ts1->add( BOOST_TEST_CASE( &test_case1 ) );
	ts1->add( BOOST_TEST_CASE( &test_case2 ) );

	boost::test_suite* ts2 = BOOST_TEST_SUITE( "test_suite2" );
	ts2->add( BOOST_TEST_CASE( &test_case3 ) );
	ts2->add( BOOST_TEST_CASE( &test_case4 ) );

	boost::framework::master_test_suite().add( ts1 );
	boost::framework::master_test_suite().add( ts2 );

	return 0;
}*/
