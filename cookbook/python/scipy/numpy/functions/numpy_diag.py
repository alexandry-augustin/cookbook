import numpy as np

if __name__=='__main__':
	a=np.array([[1, 2],[3, 4]])
	assert(np.array_equal(np.diag(a), np.array([1,4])))

