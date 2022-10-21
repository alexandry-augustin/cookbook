import numpy as np
import matplotlib.pyplot as plt
from scipy.misc import imread

if __name__=='__main__':
	np.random.seed(0)
	x=np.random.uniform(0.0,10.0,15)
	y=np.random.uniform(0.0,10.0,15)
	img=imread("lena.bmp")
	plt.scatter(x,y,zorder=1)
	plt.imshow(img,zorder=0)
	plt.show()
