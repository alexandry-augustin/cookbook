import numpy as np

if __name__=='__main__':
	a=np.array([1,2,3])
	b=np.array([1,2,3])
	assert(np.dot(a, b)==np.sum(a*b))
