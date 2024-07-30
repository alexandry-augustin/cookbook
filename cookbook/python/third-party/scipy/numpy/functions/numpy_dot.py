#dot product
#1D arrays: inner product of vectors (without complex conjugation)
#2D arrays: equivalent to matrix multiplication
#ND arrays: TODO

import numpy as np

if __name__ == '__main__':

	a=np.array([1,2,3])
	b=np.array([1,2,3])
	assert(np.dot(a, b)==np.sum(a*b))
	#--------------------------------------------------
	a=np.array([1, 2, 3], float)
	b=np.array([0, 1, 1], float)
	assert(np.dot(a, b)==5)