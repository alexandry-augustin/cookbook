import numpy as np

if __name__=="__main__":
	#--------------------------------------------------
	# delete by indices
	#--------------------------------------------------
	a=np.arange(5,8)
	index=[0,1]
	a=np.delete(a, index)
	print a
	#--------------------------------------------------
	# delete by values
	#--------------------------------------------------
	a=np.arange(5,10)
	values=np.array([5, 9, 6])
	a.sort()
	index=np.searchsorted(a, values)
	#if any of the indices == len(a), it wasn't found
	a=np.delete(a, index)
	print a
