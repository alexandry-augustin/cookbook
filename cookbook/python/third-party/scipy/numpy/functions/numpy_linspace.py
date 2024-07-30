import numpy as np

if __name__ == '__main__':

	a = np.linspace(1, 10, 4, dtype=int)
	assert(np.array_equal(a, np.array([1, 4, 7, 10])))
	
	a=np.linspace(-2, 2, 3) #return 3 evenly spaced numbers over [-2; 2]
	assert(np.array_equal(a, np.array([-2.,0,2.])))
