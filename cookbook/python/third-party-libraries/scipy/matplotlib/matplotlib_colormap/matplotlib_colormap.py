import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm

if __name__=='__main__':
	#--------------------------------------------------
	data=np.random.rand(5, 4)

	_cm=cm.Greys_r
	_cm=cm.colors.LinearSegmentedColormap.from_list(name="name", colors =['g', '.9', 'CornflowerBlue', '#FF5588'], N=11)
	_cm=cm.colors.LinearSegmentedColormap.from_list(name="name", colors =['#FFFFFF', '#000000'], N=11)

#	cdict={
#		'red'  :  ( (0.0, 0.25, .25), (0.02, .59, .59), (1., 1., 1.)),
#		'green':  ( (0.0, 0.0, 0.0), (0.02, .45, .45), (1., .97, .97)),
#		'blue' :  ( (0.0, 1.0, 1.0), (0.02, .75, .75), (1., 0.45, 0.45))
#	}
#	_cm=cm.colors.LinearSegmentedColormap('my_colormap', cdict, 1024)

	heatmap=plt.pcolor(data, cmap=_cm)
	plt.colorbar(heatmap)
	#--------------------------------------------------
	plt.show()
