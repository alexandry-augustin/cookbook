if __name__=="__main__":
	f=lambda x: x**2
	assert(f(8)==64)

	f=lambda x, y: x+y
	assert(f(1,1)==2)

	f=lambda x: True if x % 2 == 0 else False
	assert(f(1)==False)
	assert(f(2)==True)
