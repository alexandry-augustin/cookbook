"""
	Draw random samples from a multivariate normal (Gaussian) distribution.
	np.random.multivariate_normal(mean,cov,size)
"""

import numpy as np

if __name__=='__main__':
	x=np.random.multivariate_normal([0, 0], [[1,0],[0,1]], size=2) #bivariate
	print x

