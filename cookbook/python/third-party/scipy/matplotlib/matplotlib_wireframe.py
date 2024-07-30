from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np

if __name__=='__main__':
	X=np.arange(-5, 5, 0.25)
	Y=np.arange(-5, 5, 0.25)
	X, Y=np.meshgrid(X, Y)

	#Z=X+Y
	Z=np.sin(X)+np.sin(Y)
	#Z=np.sin(np.sqrt(X**2 + Y**2))
	#sigma=1
	#Z=np.exp(-X**2/(2.*sigma**2)-Y**2/(2.*sigma**2))
	#Z=Z/np.sum(Z.ravel())

	fig=plt.figure()
	ax=fig.gca(projection='3d')
	ax.plot_wireframe(X, Y, Z)
	plt.show()
