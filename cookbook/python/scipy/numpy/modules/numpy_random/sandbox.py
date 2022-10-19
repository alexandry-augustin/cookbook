import numpy as np

if __name__=='__main__':
	np.random.seed(293423)

	#uniform distribution on [0.0, 1.0) 
	a=np.random.rand(5)
	assert(a.shape==(5,))
	a=np.random.rand(2,3)
	assert(a.shape==(2,3))
	np.random.random() #single number
	np.random.randint(5, 10, size=(2,2)) #integers between 5 and 10
	np.random.uniform(-5,5,size=(3,1))

	#poisson
	np.random.poisson(6.0)

	#gaussian
	np.random.normal() #normal(0, 1)
	np.random.normal(1.5, 4.0) #normal(mean, std_dev)
	a=np.random.normal(size=5)
	assert(a.shape==(5,))
	a=np.random.normal(size=(2,5))
	assert(a.shape==(2,5))

	#standard normal
	assert(np.random.randn(3).shape==(3,))
	a=np.random.randn(2,1)
	assert(a.shape==(2,1))

	#random shuffle
	l=range(10)
	np.random.shuffle(l) #modifies in place
