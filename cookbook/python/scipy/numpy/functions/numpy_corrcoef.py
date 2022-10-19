import numpy as np

if __name__=='__main__':
	#correlation matrix
	#[[x1, x2, ...], [y1, y2, ...], [z1, z2, ...], ...]
	#c[i,j] gives the correlation coefficient for the ith and jth variables
	a=np.array([[1, 2, 1, 3], [5, 3, 1, 8]])
	np.corrcoef(a)
	np.cov(a)

