
if __name__ == '__main__':

	five = lambda: 5
	assert(five() == 5)
	
	add = lambda x,y: x+y
	assert(add(1, 2) == 3)

	add_one = lambda x: add(x, 1)
	assert(add_one(5) == 6)

	from functools import partial

	add_two = partial(add, 2)
	assert(add_two(5) == 7)
