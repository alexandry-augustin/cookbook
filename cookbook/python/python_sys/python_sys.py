import sys
#----------------------------------------------------------
if __name__=='__main__':
	print(sys.version)
	print sys.version_info 
	#if sys.version_info < (2, 4):
	#    raise "must use python 2.5 or greater"
	#--------------------------------------------------
	argc=len(sys.argv)
	assert(sys.argv[0]=='python_sys.py')
	#--------------------------------------------------
	#print('', str0, 'is', str1)

	try:
		x=input("x=")
		print("x=", x)
		#print(1, "a", sep="|")
		#print("test", end='')
	except:
		pass
	#--------------------------------------------------
	sys.stdin.read()
	sys.stdin.readline()
	sys.stdin.readlines()
	#sys.stdout.print()
	sys.stdout.write()
	sys.stdout.writelines()
	#sys.stderr.print()
	sys.stderr.write()
	sys.stderr.writelines()
	#--------------------------------------------------
	sys.exit(0)
