if __name__ == '__main__':
	s=set()
	s.add(0)
	s.add(1)
	s.add(0)
	assert(len(s)==2)
	s.update([2,3])
	assert(len(s)==4)
	for i in s:
		print(i)
	#--------------------------------------------------
	s0=set(["ab", "bc", "cd", "ab"])
	s1=set(["ab", "bc"])

	assert(s0.difference(s1)==set(['cd']))
	assert(s1.issubset(s0))
	assert(s0.issuperset(s1))
	assert(s1.union(s0)==s0)
	assert(s1.intersection(s0)==s1)
#	assert(s1.symmetric_difference(s0)==s1)
