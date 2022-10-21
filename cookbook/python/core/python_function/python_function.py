#----------------------------------------------------------
# functions do not specify the datatype of their return value
# they don't specify whether or not they return a value
#----------------------------------------------------------
#http://stackoverflow.com/questions/986006/python-how-do-i-pass-a-variable-by-reference
#If you're used to most traditional languages, you have a mental model of what happens in the following sequence:
#a = 1
#a = 2
#You believe that a is a memory location that stores the value 1, then is updated to store the value 2. That's not how things work in Python. Rather, a starts as a reference to an object with the value 1, then gets reassigned as a reference to an object with the value 2. Those two objects may continue to coexist even though a doesn't refer to the first one anymore; in fact they may be shared by any number of other references within the program.
#When you call a function with a parameter, a new reference is created that refers to the object passed in. This is separate from the reference that was used in the function call, so there's no way to update that reference and make it refer to a new object.
#----------------------------------------------------------
def f_00():
	pass
def f_01(s="NA"):
	return s
def f_02(*args): #variable length argument 
	if len(args)!=0:
		assert(args[0]==0)
		assert(args[1]==1)
		assert(args[2]==2)
def f_08(**kwargs): #variable length argument 
	pass
def f_09(*args, **kwargs): #variable length argument. *args must occur before **kwargs 
	pass
def f_03():
	return #None is optional
def f_04(x=1, y=1):
	return x-y
def f_05(n):
	n=n+1;
	return n
def f_06(a=[]):
	for n in a:
		assert(n%2==0)
def f_07(n, m):
	return n, m #returns a tuple
#def f_05(n):
#	n=n+1;
#	return n

def exec_f(f, *args):
	return f(*args)
	
def add(x,y):
	return x+y

if __name__ == '__main__':
	assert(f_00()==None)
	assert(f_01(s=5)==5)
	assert(f_04()==0)
	assert(f_04(10)==9)
	assert(f_04(10, 5)==5)
	assert(f_04(y=5, x=8)==3)

	n=0
	assert(f_05(n)==1)
	assert(n==0)

	a=[2, 4, 6]
	f_06(a)

	n_00, n_01=f_07(1, 2)
	assert(n_00==1)
	assert(n_01==2)

	assert(f_07(1,2)==(1,2))

	f_02()
	f_02(0, 1, 2)
	f_08()
	f_08(a=0, b=1, c=2)
	#f_09(a=0, b=1, c=2)
	#--------------------------------------------------
	assert(exec_f(add,1,2)==3)
