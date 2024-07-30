#----------------------------------------------------------
import numpy as np

if __name__ == '__main__':

	a=np.array([1,2])
	assert(np.array_equal(np.concatenate((a,a)), np.array([1,2,1,2])))
	#--------------------------------------------------
	u=np.array([1,2])
	v=np.array([3,4,5,6])
	w=np.array([7,8,9])
	#print type(np.concatenate((u, v, w)))
	#assert(np.array_equal(a, np.array([1, 2, 3, 4, 5, 6, 7, 8, 9]))
	#--------------------------------------------------
	# ignore item for index i
	a=np.array([0, 1, 2])
	i=1
	# print(a[i+1:])
	a=np.concatenate([a[:i], a[i+1:]])
	assert(np.array_equal(a, np.array([0, 2])))