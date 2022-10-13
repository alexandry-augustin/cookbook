import math
#from math import *

def main():
	assert(math.factorial(3)==6)
	assert(math.exp(1)==math.e)
	#assert(math.exp(math.log(5, math.e))==5) #! rounding error
	assert(math.log(math.exp(5), math.e)==5)
	assert(math.log(math.e)==1)
	assert(math.log(1)==0)
	assert(math.pow(2, 4)==16)
	assert(math.pow(2, 4)==2**4)
	assert(math.sqrt(16)==4)
	assert(100%90==10)

	n=15
	print format(n, '02x') #02: at least 2 digits x:lower-case hex
	print '%02x' % n

if __name__=='__main__':
	main()
