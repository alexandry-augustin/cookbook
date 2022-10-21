import itertools
#----------------------------------------------------------
if __name__ == '__main__':
	letters=itertools.cycle(('a', 'b', 'c')) 
	for i in range(5):
		print letters.next()
#	print(len(letters))
