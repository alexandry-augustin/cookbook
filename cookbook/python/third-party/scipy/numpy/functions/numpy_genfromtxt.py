import numpy as np
#----------------------------------------------------------
if __name__ == '__main__':
#	data=np.genfromtxt('data.csv', delimiter=';', skip_header=0,
#		     skip_footer=0, names=['x', 'y'])

	data=np.genfromtxt('data.csv', delimiter=';')
	x=data[:,0]
	y=data[:,1]
	print y
