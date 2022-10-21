import numpy as np

if __name__ == '__main__':
	x1=np.array([1,2,3,4])
	x2=[-9,-8,-7]
	X1,X2=np.meshgrid(x1,x2)
	assert(np.array_equal(X1, [[1,2,3,4],[1,2,3,4],[1,2,3,4]]))
#	assert(X2==[[-9 -8 -7]' [-9 -8 -7]' [-9 -8 -7]' [-9 -8 -7]'])

	pt=np.array([X1[1,2],X2[1,2]])
	assert(np.array_equal(pt, np.array([3,-8])))

	print X1.reshape(-1,1), X2.reshape(-1,1)
	
        x, y = np.linspace(0, 5, 50), np.linspace(-9, -6, 50)
	print x

