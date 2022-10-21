"""
	matlab: x=A\y
	numpy:  x=np.linalg.solve(A, y)

	x such that Ax=y
"""
#----------------------------------------------------------
import numpy as np

if __name__ == '__main__':
	#x such that a*x=y
	a=np.array([[3,1], [1,2]])
	y=np.array([9,8])
	x=np.linalg.solve(a, y)

	print x
	print np.dot(np.linalg.inv(a), y)
	#assert np.array_equal(x, np.dot(np.linalg.inv(a), y)))
