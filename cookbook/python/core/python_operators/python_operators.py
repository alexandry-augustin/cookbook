#and, or, not
# is, is not:
# 	checks that the two arguments refer to the same object in memory

def modulo_test():
	print 7%3

def ternary_test():
	"""
		ternary oprator (a?b:c)
	"""
	a=True
	b=False
	assert((a if a==b else b)==b)
	#--------------------------------------------------
	#conditional operator
	#C equivalent: res=(n>10)?true:false;
	n=15
	res=True if n>10 else False #from Python 2.5 onwards 
	value=[True, False][n>10]

def xor_test():
	15^10

if __name__ == '__main__':

#assert( is )
#assert( is not )
	#--------------------------------------------------
	if 0 and 1:
		pass
	#--------------------------------------------------
	ternary_test()
	xor_test()
	modulo_test()
	assert(2**2==4)
