import numpy as np

if __name__=='__main__':
	a=np.array([1,2,3])
	assert(np.amax(a)==3)

	a=np.array([[1,2,3],[4,5,6]])
	assert(np.amax(a)==6) #maximum of the flattened array
	print np.amax(a, axis=0)   # Maxima along the first axis
	print np.amax(a, axis=1)   # Maxima along the second axis
