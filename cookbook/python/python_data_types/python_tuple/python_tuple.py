#immutable list
#----------------------------------------------------------
if __name__=='__main__':
	t=()
	t=tuple()
	assert(len(t)==0)
	#--------------------------------------------------
	t=(0,) #tuple containing a single value muts include a comma
	assert(len(t)==1)
	#--------------------------------------------------
	t=(1,2,'a')
	#or
	#t=1,2,'a'

	assert(t[0]==1)
	assert(t[1]==2)
	assert(t[2]=='a')
	#--------------------------------------------------
	# list -> tuple
	l=[1,2,3]
	t=tuple(l)
	assert(t==(1,2,3))
