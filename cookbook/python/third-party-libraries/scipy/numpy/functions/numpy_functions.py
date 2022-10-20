import numpy as np

if __name__=='__main__':
	np.pi
	np.e

	#also applies to element-wise arrays
	assert(np.exp(np.log(1))==1.0)
	assert(np.cos(2*np.pi)==1.0)
	assert(np.sqrt(4)==2)
	assert(np.array_equal(np.sqrt(np.array([4,16])),np.array([2,4])))
	assert(np.floor(2.8)==2)
	assert(np.ceil(2.8)==3)
	assert(np.rint(2.5)==2) #nearest (rounded) integer

	a=np.array([np.log(1), np.log(1)])
	assert(np.array_equal(np.exp(a), np.array([1,1])))
