import numpy as np
import matplotlib.pyplot as plt


if __name__=='__main__':
	x=np.arange(0, 5)
	y=np.array([0,1,2,4,3])
	y=np.sin(2*x)
	plt.step(np.arange(0, len(y)), y)

	plt.show()
