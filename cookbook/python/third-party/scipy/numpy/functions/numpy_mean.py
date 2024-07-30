import numpy as np

if __name__ == '__main__':
	a=np.array([2, 1, 9])
	assert(np.mean(a)==4)
	assert(a.mean()==4)

	a=np.array([[2, 1],[2,5]])
	assert(np.array_equal(a.mean(0), np.array([2,3]))) #along the rows
	assert(np.array_equal(a.mean(1), np.array([1.5,3.5]))) #along the columns
