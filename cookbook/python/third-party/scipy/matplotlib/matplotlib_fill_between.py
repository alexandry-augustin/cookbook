import numpy as np
import matplotlib.pyplot as plt
#----------------------------------------------------------
def std_dev():
	data=np.random.normal(loc=0, scale=np.sqrt(1), size=(10,50)) #50 samples by time steps
	#data=np.column_stack((data, data.mean(1)))
	mean=data.mean(1)
	std=data.std(1)

	plt.plot(data, "ro")
	plt.plot(mean, "r-")
	plt.gca().fill_between(np.arange(data.shape[0]), mean+std, mean-std, facecolor="#dddddd")#, color="#dddddd")
	plt.show()
#----------------------------------------------------------
def f_00():
	x=np.arange(50)
	y1=x**2
	y2=x

	plt.plot(x, y1, color="#000000")
	plt.gca().fill_between(x, y1, y2, color="#dddddd")
	plt.plot(x, y2, color="#000000")
#----------------------------------------------------------
if __name__=='__main__':
	std_dev()
	plt.show()
