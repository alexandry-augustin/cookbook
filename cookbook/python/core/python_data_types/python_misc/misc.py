def misc():
	#print "n="+5 #nok
	str_00="n="+`5`
	assert str_00=="n=5"

	n_00=12345
	assert len(`n_00`)==5

	assert(1e3==1000)
#----------------------------------------------------------
if __name__=='__main__':
	misc()
