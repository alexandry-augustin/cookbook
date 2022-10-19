import numpy as np

if __name__=='__main__':
	a=np.arange(5,10)
	print a[np.where(a<7)]
