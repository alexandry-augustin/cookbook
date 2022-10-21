import numpy as np
#--------------------------------------------------
def bincount_(a, minlength):
	ret=np.zeros(minlength, int)
	for i in range(len(a)):
		ret[a[i]]+=1
	return ret
#--------------------------------------------------
if __name__ == '__main__':
	a=np.array([0, 1, 1, 3, 2, 1, 7])

	b=np.bincount(a)
	#array([1, 3, 1, 1, 0, 0, 0, 1])
	print b

	b=np.bincount(a, minlength=10)
	#--------------------------------------------------
	J=5
	a=np.random.randint(0, J, size=(10,))
	assert(np.array_equal(bincount_(a, J), np.bincount(a, minlength=J)))
	#--------------------------------------------------
