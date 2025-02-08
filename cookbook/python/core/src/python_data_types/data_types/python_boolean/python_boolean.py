# == same as 'is'
# != same as 'is not' (same as '<>' deprecated)
# <, <=, >, >=
#----------------------------------------------------------
if __name__ == '__main__':
	n=True
	m=False
	assert(n and m==False)
	assert(n or m==False)
	assert(not n==False) 
	#assert(!n==False) #nok
	#assert(not n!=False) #nok
	#assert(not n<>False) #nok
	assert(not n is False)
	assert(not n is not True)
