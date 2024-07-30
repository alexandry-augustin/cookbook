import numpy as np

if __name__ == '__main__':
	
	a=np.zeros((3,2))
	assert(a.shape==(3,2))
	assert(np.array_equal(a, np.array([[0.,0.],[0.,0.],[0.,0.]])))
	#--------------------------------------------------
	a=np.zeros(3, dtype=np.ndarray)
	a[0]=np.array([0,1,2])
	a[1]=np.array([3,4,5])
	a[2]=np.array([6,7,8])
	assert(a[0][1]==1)
