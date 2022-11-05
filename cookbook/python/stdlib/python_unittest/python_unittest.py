import unittest

class TestCase_00(unittest.TestCase):

	def setUp(self):

		assert(self.shortDescription()==None)
		self.fixture=range(1, 10)

	def tearDown(self):

		del self.fixture

	def test_00(self):
        """
            member function must start with 'test'
        """

		self.assertEqual(1+1, 2)
		self.assertTrue(True)
		self.assertFalse(False)

		self.failUnless(True)
		self.failIf(False)
        self.assertIs(None, None)
        
#	def test_01(self):
#		raise RuntimeError('error_00') #ERROR

if __name__ == '__main__':

#	unittest.main()

#	suite=unittest.TestSuite()
#	suite.addTest(TestCase_00)

	suite=unittest.TestLoader().loadTestsFromTestCase(TestCase_00)
#	suite.addTest(unittest.TestLoader().loadTestsFromTestCase(TestCase_01))
	result=unittest.TextTestRunner(verbosity=2).run(suite)
