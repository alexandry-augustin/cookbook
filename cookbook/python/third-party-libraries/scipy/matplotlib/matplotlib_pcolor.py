"""
	http://pyhogs.github.io/colormap-examples.html
"""
#----------------------------------------------------------
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm
#----------------------------------------------------------
if __name__=='__main__':
	#--------------------------------------------------
	delta=0.025
	x=np.arange(-5.0, 5.0, delta)
	y=np.arange(-5.0, 5.0, delta)
	X, Y=np.meshgrid(x, y)
	Z=np.sin(X)+np.sin(Y)

#	nx, ny=np.shape(Z)
	cs=plt.pcolor(np.transpose(Z))
#	cb=plt.colorbar(cs, orientation = 'horizontal')
	plt.show()
	#--------------------------------------------------
	data=np.random.rand(5, 4)
	heatmap=plt.pcolor(data, cmap=cm.Greys_r)
	
	for y in range(data.shape[0]):
	    for x in range(data.shape[1]):
	        plt.text(x + 0.5, y + 0.5, '%.4f' % data[y, x],
	                 horizontalalignment='center',
	                 verticalalignment='center',
	                 )
	
	plt.colorbar(heatmap)
	#--------------------------------------------------
	plt.show()
