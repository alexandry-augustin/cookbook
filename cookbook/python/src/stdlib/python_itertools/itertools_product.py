import itertools

if __name__ == '__main__':

	#Cartesian product
	l = [
		[ 1, 2, 3 ],
		[ 'a', 'b' ],
		[ 4, 5 ]
	]
#	for element in itertools.product(*somelists):
#	for element in itertools.product([1,2,3],['a','b'],[4,5]):
	for element in itertools.product([0,1],[0,1],[0,1]):
		print(element)

	# For Python  2.5 and older
	print([(a, b, c) for a in [1,2,3] for b in ['a','b'] for c in [4,5]])

	for element in itertools.product([0,1], repeat=3):
		print(element)

	l = [ i for i in itertools.product('ABCD', 'xy') ]
	print(l)

	l = [ i for i in itertools.product(range(2), repeat=3) ]
	print(l)
