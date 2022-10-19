#----------------------------------------------------------
import numpy as np

if __name__=='__main__':
	a=np.array([1,2])
	assert(np.array_equal(np.concatenate((a,a)), np.array([1,2,1,2])))

