import numpy as np
import matplotlib.pyplot as plt

if __name__=='__main__':
	#as multinomial prior
	alpha=np.ones(3)
	p=np.random.dirichlet(alpha, 1).ravel()
	n=np.random.multinomial(1, p, size=10)
	x=np.argmax(n, axis=1)

#	print p
#	print n
#	
#	plt.bar(np.arange(3), p)
#	plt.show()



	a=np.ones(3)
	a[0]=2
	print a
	print np.random.dirichlet(a, 1).ravel()
