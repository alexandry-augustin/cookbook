class base():
	def __init__(self):
		self.n=0
#----------------------------------------------------------
def dir_test():
	"""
		return attributes of an object
	"""
	n=5
	print(dir(n))
	print(n.__str__)
#----------------------------------------------------------
def id_test():
	"""
		part of the attribute of an object
		memory address of the object (pointer in C)
		"CPython implementation detail: For CPython, id(x) is the memory address
		where x is stored"
		https://docs.python.org/3/reference/datamodel.html#objects-values-and-types

		The operators "is" and "is not" test for object identity
	"""
	m=5
	n=m
	o=m
	p=5
	assert(id(m)==id(n)==id(o)==id(p))

	n=5
	print(id(n))
	n=6
	print(id(n))
#----------------------------------------------------------
def type_test():
	n=2
	print(type(n))
#----------------------------------------------------------
m=0
#----------------------------------------------------------
def misc_test():
	assert(True)
	assert(not False)
	#--------------------------------------------------
	assert('n' not in globals())
	assert('n' not in locals())
	n=0
	assert('n' not in globals())
	assert('n' in locals())
	#--------------------------------------------------
	assert('m' in globals())
	assert('m' not in locals())
	#--------------------------------------------------
	b=base()
	assert('b' not in globals())
	assert('b' in locals())
	assert(hasattr(b, 'n'))
	assert(not hasattr(b, 'm'))
#----------------------------------------------------------
if __name__=='__main__':
	misc_test()
	dir_test()
	id_test()
	type_test()
	#sorted() see list.py
