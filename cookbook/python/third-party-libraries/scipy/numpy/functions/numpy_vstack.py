"""
Stack arrays in sequence vertically (row wise).
"""

import numpy as np

if __name__=='__main__':
	a=np.array([1, 2])
	assert(np.array_equal(np.vstack((a,[3,4])), np.array([[1,2],[3,4]])))
	assert(np.array_equal(a, np.array([1,2])))
#assert(np.array_equal(np.vstack((a,b)), np.array([[1,2],[3,4],[5,6]])))
