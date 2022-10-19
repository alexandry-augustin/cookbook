"""
	Return a flattened array.
	somewhat the oposite of reshape()
	ravel(a, order='C') {'C','F', 'A', 'K'}
		'C' means to index the elements in C-like order, with the last axis index changing fastest, back to the first axis index changing slowest.
		'F' means to index the elements in Fortran-like index order, with the first index changing fastest, and the last index changing slowest.
		Note that the 'C' and 'F' options take no account of the memory layout of the underlying array, and only refer to the order of axis indexing.
		'A' means to read the elements in Fortran-like index order if a is Fortran contiguous in memory, C-like order otherwise.
		'K' means to read the elements in the order they occur in memory, except for reversing the data when strides are negative.

	ravel() returns a view of the array
	cf flatten() for a new memory allocation
"""

import numpy as np

if __name__=='__main__':
	#order = C F A K (default=C)
	a=np.array([[1, 2], [3, 4]])
	assert(np.array_equal(a.ravel(), [1,2,3,4])) #row first
	assert(np.array_equal(np.ravel(a,"F"), [1,3,2,4])) #col first
	assert(np.array_equal(a.ravel("C"), [1,2,3,4]))

	assert(a[0][0]==1)
	assert(a.ravel()[0]==1)
	a.ravel()[0]=0
	assert(a[0][0]==0)

