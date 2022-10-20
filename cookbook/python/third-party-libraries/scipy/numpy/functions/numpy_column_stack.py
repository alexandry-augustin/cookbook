import numpy as np
#----------------------------------------------------------
if __name__=='__main__':
	a=np.array((1,2,3))
	b=np.array((2,3,4))
	assert(np.array_equal(np.column_stack((a,b)), np.array([[1,2], [2,3], [3,4]])))
