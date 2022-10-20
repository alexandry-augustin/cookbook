from collections import deque
#----------------------------------------------------------
if __name__=='__main__':
	d=deque()
	d.append(0)
	d.append(1)
	d.append(2)
	assert len(d)==3

	while len(d)>0:
		print d.pop()
