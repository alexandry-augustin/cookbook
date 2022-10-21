from mpl_toolkits.mplot3d import *
import matplotlib.pyplot as plt
import numpy as np
from random import random, seed
from matplotlib import cm
#----------------------------------------------------------
def f_01():
	fig = plt.figure()
	ax = fig.gca(projection='3d')               # to work in 3d
	plt.hold(True)

	x_surf=np.arange(0, 1, 0.01)                # generate a mesh
	y_surf=np.arange(0, 1, 0.01)
	x_surf, y_surf = np.meshgrid(x_surf, y_surf)
	z_surf = np.sqrt(x_surf+y_surf)             # ex. function, which depends on x and y
	ax.plot_surface(x_surf, y_surf, z_surf, cmap=cm.hot);    # plot a 3d surface plot

	n = 100
	seed(0)                                     # seed let us to have a reproducible set of random numbers
	x=[random() for i in range(n)]              # generate n random points
	y=[random() for i in range(n)]
	z=[random() for i in range(n)]
	scat=ax.scatter(x, y, z, color='black');                        # plot a 3d scatter plot
	scat.set_edgecolors=scat.set_facecolors = lambda *args:None #hack to remove transparency (depthshade=False) #http://stackoverflow.com/questions/15533246/controlling-alpha-value-on-3d-scatter-plot-using-python-and-matplotlib
#----------------------------------------------------------
def f_02():
	x=[0,1,2,3]
	y=[1,2,2,1]
	plt.scatter(x, y)
#----------------------------------------------------------
if __name__=='__main__':
	f_02()
	plt.show()
