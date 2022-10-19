""" 
	Cholesky decomposition
	'upper' by default
"""
#----------------------------------------------------------
import numpy as np

if __name__=='__main__':
	A=np.array([[4,12,-16],[12,37,-43],[-16,-43,98]])
	L=np.linalg.cholesky(A)
	assert(np.array_equal(L, np.array([[2.,0.,0.],[ 6.,1.,0.],[-8.,5.,3.]])))

