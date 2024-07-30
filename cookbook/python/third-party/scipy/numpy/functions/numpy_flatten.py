"""
	==ravel() with a new memory allocation
"""
import numpy as np

if __name__ == '__main__':
	a=np.array([[1, 2], [3, 4]])
	assert(np.array_equal(a.flatten(), np.array([1,2,3,4]))) #row first
	assert(np.array_equal(a.flatten("F"), [1,3,2,4])) #col first. matlab a(:)
	assert(np.array_equal(a.flatten(1), [1,3,2,4]))

	assert(a[0][0]==1)
	assert(a.flatten()[0]==1)
	a.flatten()[0]=0
	assert(a[0][0]==1)

    # check flatten() behaviour in multi-dimension
    a = np.array([[[0,1], [2,3]], [[4,5], [6,7]]])
    assert(a.flatten().all() == np.arange(8).all())