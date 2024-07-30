import math
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt

if __name__=='__main__':
	mean=0
	sigma=1
	x=np.linspace(-3,3,100)
	y=mlab.normpdf(x,mean,sigma)

	plt.plot(x,y)
	plt.show()
