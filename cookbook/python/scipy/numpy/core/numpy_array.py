# same as list but with the same type
#http://sebastianraschka.com/Articles/2014_matlab_vs_numpy.html
#numpy does not support jagged arrays natively
#----------------------------------------------------------
import pdb, sys
import numpy as np

if __name__=='__main__':
	#--------------------------------------------------
	#empty array
	a=np.empty([2, 2]) #given shape without initialising entries
	assert(a.shape==(2,2))
	#--------------------------------------------------
	#uni-dimensional arrays
	a=np.array([1,2,3])
	assert(a.shape==(3,))

	a=np.array([[1,2,3]])
	assert(a.shape==(1,3))
	#--------------------------------------------------
	#2D to 1D
	#Use np.ravel (for a 1D view) or np.flatten (for a 1D copy) or np.flat (for an 1D iterator):
	#http://stackoverflow.com/questions/13730468/from-2d-to-1d-arrays
	a=np.array([[1,2,3]])
	assert(a.shape==(1,3))
	#or
	assert(np.shape(a)==(1,3))
	a=a.ravel()
	assert(a.shape==(3,))
	#--------------------------------------------------
	a=np.array([[1,2,3], [4,5,6]]) #matlab: A=[1 2 3; 4 5 6; 7 8 9]
	assert(a[1,0]==4)
	assert(a.shape==(2,3)) #matlab: size(A)
	assert(len(a)==2) #len of 1st axi
	assert(6 in a) #check if value is present
	#--------------------------------------------------
	a=np.array([2,4,6,8,10])
	assert(np.array_equal(a[[1,3]], np.array([a[1],a[3]])))
	#--------------------------------------------------
	#operators
	a=np.array([0,1])
	b=np.array([1,1])
	assert(np.array_equal(a+b,np.array([1,2])))

	#multiplication/dot product	
	a=np.array([[0,1],[1,1]])
	b=np.array([[0,1],[1,1]])
	assert(np.array_equal(a*b, np.array([[0,1],[1,1]]))) #elementwise multiplication
	assert(np.array_equal(np.dot(a,b), np.array([[1,1],[1,2]]))) #matrix multiplication
	#--------------------------------------------------
	#fill
	a=np.array(range(3))
	a.fill(0) #cf np.ones(3), np.zeros(3)
	assert(np.array_equal(a, np.array([0, 0, 0])))
	#--------------------------------------------------
	#deep copy
	b=a.copy()
	#--------------------------------------------------
	#transpose
	a=np.array([[1,2,3],[4,5,6]])
	b=a.transpose()
	assert(np.array_equal(b, np.array([[1, 4], [2, 5], [3, 6]])))

	b=a.T
	assert(np.array_equal(b, np.array([[1, 4], [2, 5], [3, 6]])))

	a=np.array([0,1,2])
	b=a.T
	assert(np.array_equal(b, np.array([0, 1, 2])))
	#--------------------------------------------------
	#concatenate
	u=np.array([1,2])
	v=np.array([3,4,5,6])
	w=np.array([7,8,9])
	#print type(np.concatenate((u, v, w)))
	#assert(np.array_equal(a, np.array([1, 2, 3, 4, 5, 6, 7, 8, 9]))
	#--------------------------------------------------
	#ignore item for index i
	a=np.array([0, 1, 2])
	i=1
	print a[i+1:]
	a=np.concatenate([a[:i], a[i+1:]])
	assert(np.array_equal(a, np.array([0, 2])))
	#--------------------------------------------------
	#to list
	a=np.array([[1,2,3],[4,5,6]])
	l=a.tolist()
	assert(l==[[1,2,3],[4,5,6]])
	#--------------------------------------------------
	#to/from string
	a=np.array([[1,2,3],[4,5,6]])
	s=a.tostring()
	np.fromstring(s)
	#--------------------------------------------------
	#squeeze
	#a=???
	a.squeeze()
	a=np.array([[0,1],[1]])
	#--------------------------------------------------
	a=np.array([[1,2,3],[4,5,6]])
	assert(a.ndim==2)
	assert(a.shape==(2,3))
	#--------------------------------------------------
	#test for equality
	a=np.array([[1,1,1]])
	b=a+a
	c=np.array([[2,2,2]])

	#* this solution can have a strange behavior in a particular case: if either A or B is empty and the other one contains a single element, then it return True. For some reason, the comparison A==B returns an empty array, for which the all operator returns True.
	#* Another risk is if A and B don't have the same shape and aren't broadcastable, then this approach will raise an error.
	assert((b==c).all())

	assert(np.array_equal(b,c))  # test if same shape and same elements values
	assert(np.array_equiv(b,c))  # test if broadcastable shape and same elements values
	assert(np.allclose(b,c)) # test if same shape and elements have close enough values
	#--------------------------------------------------
	#arrange: array-valued version of the built-in Python range()
	a=np.arange(0., 2., 0.5) #matlab: 0:.5:(2-.5)
	assert(np.array_equal(a, np.array([0.,.5,1.,1.5])))

	a=np.arange(2,4) #matlab 2:(4-1)
	assert(np.array_equal(a, np.array([2, 3])))

	a=np.arange(2) #matlab 0:(2-1)
	assert(np.array_equal(a, np.array([0, 1])))
	#--------------------------------------------------
	#linspace
	a=np.linspace(-2,2,3) #return 3 evenly spaced numbers over [-2; 2]
	assert(np.array_equal(a, np.array([-2.,0,2.])))
	#---------------------------------------------------------
	a=np.array([[1,2],[3,4]], float)
	assert(np.array_equal(a, np.array([[1.,2.],[3.,4.]])))
	#--------------------------------------------------
	#dot product
	#1D arrays: inner product of vectors (without complex conjugation)
	#2D arrays: equivalent to matrix multiplication
	#ND arrays: TODO
	a=np.array([1, 2, 3], float)
	b=np.array([0, 1, 1], float)
	assert(np.dot(a, b)==5)
	#--------------------------------------------------
	#exponentiation
	a=np.array([2,4])
	a=a**2 #elementwise operation
	assert(np.array_equal(a, np.array([4,16])))
	#--------------------------------------------------
	#column/slice notation
	a=np.array([0,1,2])
	assert(np.array_equal(a[0:1], [0]))
	assert(np.array_equal(a[0:2], [0, 1]))
	assert(np.array_equal(a[1:-1], [1]))

	a=np.array([[1,2,3],[4,5,6]])
	assert(np.array_equal(a[:,1], [2,5]))
	assert(np.array_equal(a[1,:], [4,5,6]))
	print a[:,:]
	
	a=np.array([[1,2,3],[4,5,6]])
	assert(np.array_equal(a[a.shape[0]-1,:],np.array([4,5,6]))) #last row
	b=a[a.shape[0]-1,:]
	b[2]=9 #modifies a
	assert(np.array_equal(a[a.shape[0]-1,:],np.array([4,5,9])))
	#--------------------------------------------------
	a=np.array([1])
	a[0]+=1
	#print a

	a=np.array(["1"], float)
	a[0]+=1
	#print a
	#--------------------------------------------------
	#jagged array
	a=np.zeros(3, dtype=np.ndarray)
	a[0]=np.array([0])
	a[1]=np.array([3,4])
	a[2]=np.array([6,7,8])

	print a[2]
	#--------------------------------------------------
	a=np.zeros(3, dtype=np.ndarray)
	a[0]=np.array([0,1,2])
	a[1]=np.array([3,4,5])
	a[2]=np.array([6,7,8])
	assert(a[0][1]==1)

	b=np.ones((3,3))
	c=a+b
#	assert(c[0][1]==2)
	print c[0][1]
	#--------------------------------------------------
	a=np.empty(1, float)
	print a.dtype #float64
	#--------------------------------------------------
	#Structured arrays
	#http://docs.scipy.org/doc/numpy/user/basics.rec.html
	#http://people.rit.edu/blbgse/pythonNotes/numpy.html
	#--------------------------------------------------
	a=np.zeros(10*3*3).reshape(10,3,3)
	print a
	#--------------------------------------------------
	#delete()
	a=np.arange(5,10)
	#print np.delete(a, 2) #remove item at index 2 (value 7)
	a=np.delete(a, np.where(a==7))#remove item with value 7
	assert(np.array_equal(a, np.array([5,6,8,9])))

