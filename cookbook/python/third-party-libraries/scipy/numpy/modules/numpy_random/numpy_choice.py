"""
"""

import numpy as np

if __name__=='__main__':
	print np.random.choice(10, size=3, replace=False) #sample 3 random elements in [0,9] without replacement

	# p: The probabilities associated with each entry in a. If not given the sample assumes a uniform distribution over all entries in a.
	print np.random.choice(3, size=3, p=[.1, .8, .1]) #sample 3 random elements in [0,9] without replacement (default: uniform)
	
