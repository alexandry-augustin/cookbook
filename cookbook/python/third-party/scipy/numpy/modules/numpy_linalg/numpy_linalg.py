""" linear algebra sub-module """
#----------------------------------------------------------
import numpy as np

if __name__ == '__main__':
	#determinant
	a=np.array([[4,2,0], [9,3,7], [1,2,1]])
#	assert(np.linalg.det(a)==-48.0)
	print np.linalg.det(a)
	#--------------------------------------------------
	#
	#np.linalg.eig(a)
	#np.linalg.inv(a)
	#np.linalg.svd(a)
	#--------------------------------------------------
	#np.linalg.inv(a)
