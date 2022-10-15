import random

if __name__=='__main__':

	random.seed(0)

	random.random()        # Random float x, 0.0 <= x < 1.0
	random.uniform(1, 10)  # Random float x, 1.0 <= x < 10.0
	assert(random.randint(1, 10)<=10)  # Integer from 1 to 10, endpoints included
	random.randrange(0, 101, 2)  # Even integer from 0 to 100
	random.choice('abcdefghij')  # Choose a random element
	print random.choice(['a', 'b'])
	items=[1, 2, 3, 4, 5, 6, 7]
	random.shuffle(items)

	random.sample([1, 2, 3, 4, 5],  3)  #sample 3 elements without repetitions
	#numpy version of random.sample():
#	a=np.arange(20)
#	np.random.shuffle(a)
#	print a[:10]
