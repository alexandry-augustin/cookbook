import unittest
from base import add
from base import substract

class BaseTestCase(unittest.TestCase):
	def setUp(self):
		pass
	def test_add(self):
		self.assertEqual(add(1, 1), 2)
	def test_substract(self):
		self.assertEqual(substract(1, 1), 0)

if __name__ == '__main__':
	unittest.main()
