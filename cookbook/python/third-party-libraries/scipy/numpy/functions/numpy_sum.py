"""
	sum	
"""
import numpy as np

if __name__ == '__main__':
	#2d
	a=np.array([[0, 1], [0, 5], [0, 2]])
	assert(a.shape==(3,2))
	assert(np.sum(a)==8) #(axis = None) performs a sum over all the dimensions
	assert(np.array_equal(np.sum(a,0), np.array([0,8]))) #(axis 0) along cols
	assert(np.array_equal(np.sum(a,1), np.array([1,5,2]))) #(axis 1) along rows 

	#3d
#	a=np.array([
# [[0, 0, 1], [0, 0, 1], [0, 0, 1]],\
# [[0, 0, 1], [0, 0, 1], [0, 0, 1]],\
# [[0, 0, 1], [0, 0, 1], [0, 0, 1]]\
#	])
	n=3
	a=np.array([[[1 for k in xrange(n)] for j in xrange(n)] for i in xrange(n)])
	print a
	print np.sum(a, 1)
