import numpy as np
from scipy import stats

if __name__=='__main__':

	mode=stats.mode([1,2,3,1,2,1,1,1,3,2,2,1])
	#mode[0] sorted most freq values
	#mode[1] count of the most freq values
	print mode
	#-------------------------------------------------
	a = np.array([[1, 3, 4, 2, 2, 7],
		      [5, 2, 2, 1, 4, 1],
		      [3, 3, 2, 2, 1, 1]])

	print stats.mode(a)
	print stats.mode(a)[0].ravel()
