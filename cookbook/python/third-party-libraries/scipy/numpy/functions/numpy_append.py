import numpy as np

if __name__ == '__main__':
	print np.append([1, 2, 3], [[4, 5, 6], [7, 8, 9]])
	print np.append([[1, 2, 3], [4, 5, 6]], [[7, 8, 9]], axis=0)	
