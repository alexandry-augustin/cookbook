"""
    Broadcasting describes how arithmetic works between arrays of different shapes.
"""
import numpy as np

if __name__ == '__main__':

	#addition
	a=np.array([0,1,2])
	assert(a.shape==(3,))
	b=np.array([0,1]).reshape(-1,1)
	assert(b.shape==(2,1))
	assert(np.array_equal(a+b, b+a))
	assert((a+b).shape==(2,3))
	assert(np.array_equal(a+b, np.array([[0,1,2],[1,2,3]])))


	a=np.array([[2, 1],[2,5], [2,3]])
	a=a-a.mean(0)

	a=np.array([0,1,2]).reshape(-1,1)
	print(a+a.T)
	print(a.T+a)
