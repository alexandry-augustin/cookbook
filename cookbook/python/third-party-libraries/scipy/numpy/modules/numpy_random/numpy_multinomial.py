import numpy as np

if __name__=='__main__':
	temp=np.random.multinomial(1, [1/6.]*6, size=1) #sample from multinomial
	print temp
	print np.argmax(temp, axis=1)
