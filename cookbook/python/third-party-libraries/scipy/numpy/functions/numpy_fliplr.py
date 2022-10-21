import numpy as np

if __name__ == '__main__':
	a=np.array([[1,2,3],[4,5,6]])
	assert(np.array_equal(np.fliplr(a), np.array([[3,2,1],[6,5,4]])))
