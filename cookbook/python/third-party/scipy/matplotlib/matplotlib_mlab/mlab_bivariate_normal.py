"""
	 matplotlib.mlab.bivariate_normal(X, Y, sigmax=1.0, sigmay=1.0, mux=0.0, muy=0.0, sigmaxy=0.0)
"""
#----------------------------------------------------------
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

if __name__=='__main__':
	delta=0.025
	x=np.arange(-2.0, 2.0, delta)
	y=np.arange(-2.0, 2.0, delta)
	X, Y=np.meshgrid(x, y)
	Z=mlab.bivariate_normal(X, Y, 1.0, 1.0, 0.0, 0.0, .0)
	assert(Z.shape==(160,160))

	plt.figure()
	plt.contour(X, Y, Z, 2)
	plt.show()
