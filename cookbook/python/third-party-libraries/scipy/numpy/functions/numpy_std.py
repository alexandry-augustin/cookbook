"""
	std deviation
"""
#----------------------------------------------------------
import numpy as np
#----------------------------------------------------------
if __name__ == '__main__':
	a=np.array([2, 1, 9])
	assert(round(a.std(),2)==3.56)
