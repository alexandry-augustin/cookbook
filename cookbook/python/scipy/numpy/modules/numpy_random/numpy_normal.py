"""
	Draw random samples from an univariate normal (Gaussian) distribution.
	np.random.normal(loc=mu, scale=std_dev, size)
"""

import numpy as np

if __name__=='__main__':
	x=np.random.normal(loc=0, scale=np.sqrt(1), size=2)
	print x

