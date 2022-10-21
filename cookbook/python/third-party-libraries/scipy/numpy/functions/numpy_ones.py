import numpy as np

if __name__ == '__main__':

	a=np.ones((3,2))
	assert(a.shape==(3,2))
	assert(np.array_equal(a, np.array([[1.,1.],[1.,1.],[1.,1.]])))
