import numpy as np

if __name__=='__main__':
	a=np.array([2, 2])
	assert(np.prod(a)==4)

	a=np.array([[1,2,3], [4,5,6]])
	assert(np.prod(a)==720)
	assert(np.array_equal(np.prod(a, 0), np.array([4,10,18])))
	assert(np.array_equal(np.prod(a, 1), np.array([6,120])))

	a=np.array([[0,2,3], [4,5,6]])
	assert(np.prod(a)==0)
