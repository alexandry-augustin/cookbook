"""
	http://stackoverflow.com/questions/9566592/find-multiple-values-within-a-numpy-array
"""
import numpy as np

if __name__=="__main__":
	#--------------------------------------------------
	# 
	#--------------------------------------------------
	a=np.arange(5, 10)
	values=np.asarray([5, 9])
	a.sort()
	index=np.searchsorted(a, values)
	assert(np.array_equal(index, np.array([0, 4])))
	print index
