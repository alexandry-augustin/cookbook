import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt

if __name__=='__main__':
	# Plot between -10 and 10 with .001 steps.
	range = np.arange(-10, 10, 0.001)
	# Mean = 0, SD = 2.
	plt.plot(range, norm.pdf(range,0,2))

	plt.show()
