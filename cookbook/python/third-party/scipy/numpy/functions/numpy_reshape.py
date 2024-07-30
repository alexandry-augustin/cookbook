#----------------------------------------------------------
import numpy as np

if __name__ == '__main__':
	a=np.arange(6)
	b=a.reshape((2,3))
	c=a.reshape(2,3)
	assert(np.array_equal(b, np.array([[0,1,2],[3,4,5]])))
	assert(np.array_equal(c, np.array([[0,1,2],[3,4,5]])))
	print a.reshape(2,3,order='F') #default='C'

	#One dimension can be -1: the value is inferred from the length of the array and remaining dimensions
	b=a.reshape((-1,3))
	c=a.reshape((2,-1))
	assert(np.array_equal(b, np.array([[0,1,2],[3,4,5]])))
	assert(np.array_equal(c, np.array([[0,1,2],[3,4,5]])))

	#tranpose
	b=a.reshape(-1,1)
	assert(np.array_equal(b, np.array([[0],[1],[2],[3],[4],[5]])))

