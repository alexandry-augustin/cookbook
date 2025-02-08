import math
#----------------------------------------------------------
def roundint(x, base=5):
	"""
		http://stackoverflow.com/questions/2272149/round-to-5-or-other-number-in-python
		10 -> 10
		12 -> 10
		13 -> 15
		14 -> 15
		16 -> 15
		18 -> 20
	"""
	return int(base * round(float(x)/base))
#----------------------------------------------------------
if __name__ == '__main__':
	f=float('-inf')
	f=float('inf')
	f=float('nan')
	print f
	print math.isnan(f)
	#--------------------------------------------------
	# Rounding
	#--------------------------------------------------
	f=1.26
	f=float("%.1f"%f)
	assert(f==1.3)

	print math.ceil(f)
	print math.floor(f)
	print round(f)

	a=range(20)
	print map(roundint, a)
