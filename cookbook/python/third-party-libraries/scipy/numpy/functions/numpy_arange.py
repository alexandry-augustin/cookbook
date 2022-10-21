# array-valued version of the built-in Python range()

import numpy as np

if __name__ == '__main__':

	a=np.arange(0., 2., 0.5) #matlab: 0:.5:(2-.5)
	assert(np.array_equal(a, np.array([0.,.5,1.,1.5])))

	a=np.arange(2,4) #matlab 2:(4-1)
	assert(np.array_equal(a, np.array([2, 3])))

	a=np.arange(2) #matlab 0:(2-1)
	assert(np.array_equal(a, np.array([0, 1])))
