import numpy as np
import matplotlib.pyplot as plt

if __name__=='__main__':
	x=np.linspace(0, 1)
	#y=np.sin(4*np.pi*x)*np.exp(-5*x)
	y=x**2

	plt.fill(x, y, 'r')
	plt.grid(True)
	plt.show()
