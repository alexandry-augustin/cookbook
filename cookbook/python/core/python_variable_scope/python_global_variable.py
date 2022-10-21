#----------------------------------------------------------
#http://effbot.org/pyfaq/what-are-the-rules-for-local-and-global-variables-in-python.htm
#Variables that are only referenced inside a function are implicitly global.
#If a variable is ever assigned a new value inside the function, the variable is implicitly local, and you need to explicitly declare it as global.
#
#On one hand, requiring global for assigned variables provides a bar against unintended side-effects.
#On the other hand, if global was required for all global references, you'd be using global all the time. You'd have to declare as global every reference to a builtin function or to a component of an imported module. This clutter would defeat the usefulness of the global declaration for identifying side-effects.
#----------------------------------------------------------
n=0 #optional
#----------------------------------------------------------
def set_00(m):
	n=m #local

def set_01(m):
	global n #needed when writting
	n=m

def get_00():
	return n #not needed when reading

def f_00(m):
	assert(n==m) #n is global

def f_01():
	print unknown_var #global, will fail

def f_02():
	try:
		print g_00
	except UnboundLocalError:
		#UnboundLocalError: local variable 's' referenced before assignment
		pass
	g_00="123"	
#----------------------------------------------------------
def test_00():
	set_00(5)	
	assert(n==0)

	set_01(5)	
	assert(n==5)

	set_01(1)
	f_00(get_00())
#----------------------------------------------------------
if __name__ == '__main__':
	test_00()

	g_00="abc"
	f_02()
