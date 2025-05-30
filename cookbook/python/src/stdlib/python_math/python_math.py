import math

def test_exp_log():

	assert(math.exp(1) == math.e)
	#assert(math.exp(math.log(5, math.e)) == 5) #! rounding error
	assert(math.log(math.exp(5), math.e) == 5)
	assert(math.log(math.e) == 1)
	assert(math.log(1) == 0)

def test_isclose():
	"""

	math.isclose(a, b, rel_tol, abs_tol)
	
	rel_tol: (Optional) The relative tolerance. It is the maximum allowed difference between value a and b. Default value is 1e-09
	abs_tol: (Optional) The minimum absolute tolerance. It is used to compare values near 0. The value must be at least 0

	Equivalent function (https://peps.python.org/pep-0485/#proposed-implementation):

		def isclose(a, b, rel_tol=1e-09, abs_tol=0.0):
				return abs(a-b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)
	"""

	a = math.isclose(0, 0.9, rel_tol=1) # relative tolerance (maximum allowed difference, relative to the larger absolute value)
	# a = math.isclose(.5, .59, abs_tol=) # absolute tolerance
	print(a)

if __name__ == '__main__':

	assert(math.factorial(3) == 6)
	assert(math.pow(2, 4) == 16)
	assert(math.pow(2, 4) == 2**4)
	assert(math.sqrt(16) == 4)
	assert(100%90 == 10)

	n = 15
	print(format(n, '02x')) #02: at least 2 digits x:lower-case hex
	print('%02x' % n)

	test_exp_log()
	test_isclose()
