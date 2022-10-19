import numpy as np

if __name__=='__main__':
	a=np.array([2, 1, 9, float('nan')])
	assert(np.isnan(np.mean(a)))
	assert(np.nanmean(a)==4)
