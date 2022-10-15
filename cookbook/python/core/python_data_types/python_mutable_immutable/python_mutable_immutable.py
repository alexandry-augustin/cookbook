# name, binding, mutable, immutable

# immutable: None, string, bytes, int, complex, float, tuple, frozen set
# mutable: user-defined, list, dictionary, set, byte array

def f_unsafe(a=[]): 
	"""
		do not put mutable objects as default value of a function parameter.
		immutable objects are safe
	"""
	a.append(0)
	return a

def f_safe(a=None): 
	if a==None:
		a=[]
	a.append(0)
	return a

if __name__=="__main__":
	f_unsafe()
	assert(f_unsafe()==[0, 0])

	f_safe()
	assert(f_safe()==[0])
