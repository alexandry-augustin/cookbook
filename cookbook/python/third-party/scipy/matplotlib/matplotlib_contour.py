"""
	 matplotlib.mlab.bivariate_normal(X, Y, sigmax=1.0, sigmay=1.0, mux=0.0, muy=0.0, sigmaxy=0.0)
"""
#----------------------------------------------------------
import matplotlib
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import math
#----------------------------------------------------------
if __name__=='__main__':
	delta=0.025
	x=np.arange(-5.0, 5.0, delta)
	y=np.arange(-5.0, 5.0, delta)
	X, Y=np.meshgrid(x, y)
	Z=mlab.bivariate_normal(X, Y)
#Z=np.sin(X)+np.sin(Y)

	plt.figure()
	plt.contour(X, Y, Z, 2) #2 levels

	plt.figure()
	plt.contour(X, Y, Z, levels=[.000001])

	plt.show()
