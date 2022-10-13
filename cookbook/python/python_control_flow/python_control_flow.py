def switch(x):  #switch_case emulation
	return {
		'a': 1,
		'b': 2,
	}.get(x, 9)    # 9 is default if x not found
#----------------------------------------------------------
if __name__=='__main__':
	i=0
	while i<10:
		if i==0:
			i+=1
			continue
		elif i==5:
			break
		print(i)
		i+=1 
	#--------------------------------------------------
	while True: 
	#or while 1:
		#continue
		#or pass
		break
	#--------------------------------------------------
	if i==0:
		i+=1
	else:
		i=0
	#--------------------------------------------------
	n=0
	for i in range(5): #0 1 2 3 4
		assert(i==n)
		n+=1
	#--------------------------------------------------
	l=['a', 'b', 'c']
	for c in l:
		print(c)
	for c in reversed(l):
		print(c)
	#--------------------------------------------------
	#conditional operator
	value = 1 if 1 > 2 else 2
	assert value == 2
	#--------------------------------------------------
	while True:
		if 1+1==2: break
	#--------------------------------------------------
	a=["zero", "one", "two"]
	for i, name in enumerate(a):
		print i, name
	#--------------------------------------------------
	a=[5,6,7]
	for i, name in enumerate(a):
		print i, name
