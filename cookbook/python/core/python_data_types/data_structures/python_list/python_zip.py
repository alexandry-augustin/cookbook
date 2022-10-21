if __name__ == '__main__':

	#assert(zip([1,2,3],[4,5,6])==[(1, 4), (2, 5), (3, 6)]) # Python 2.x
	assert(list(zip([1,2,3],[4,5,6]))==[(1, 4), (2, 5), (3, 6)]) # Python 3.x

	#assert(zip([1,2],[3,4],[5,6])==[(1, 3, 5), (2, 4, 6)]) # Python 2.x
	#--------------------------------------------------
	#matrix transpose
	m=list()
	for row in range(3):
		m.append([row]*3)
	m=zip(*m)
	for row in m:
		print(row)
