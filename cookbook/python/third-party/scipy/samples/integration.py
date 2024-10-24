# http://stackoverflow.com/questions/13320262/calculating-the-area-under-a-curve-given-a-set-of-coordinates-without-knowing-t
import numpy as np
from scipy.integrate import simps
#import scipy as sp

if __name__=="__main__":

	y = np.array([5, 20, 4, 18, 19, 18, 7, 4])

	# Compute the area using the composite trapezoidal rule.
	area = np.trapz(y, dx=5)
	print("area =", area)

	# Compute the area using the composite Simpson's rule.
	area = simps(y, dx=5)
	print("area =", area)
