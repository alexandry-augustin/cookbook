#super() cannot be used with an old-style class
#----------------------------------------------------------
class base_00(object):
        def __init__(self, n):
		print("[base_00::__init__]")
		self.n=n
#----------------------------------------------------------
class base_01(base_00):
        def __init__(self, n):
		super(base_01, self).__init__(n)
		print("[base_01::__init__]")
#	def __str__(self):
#		return "[base_01::__str__]"
#----------------------------------------------------------
class base_02(base_00):
        def __init__(self, n):
		super(base_02, self).__init__(n)
		print("[base_02::__init__]")
#----------------------------------------------------------
class base_03(object):
        def __str__(self):
		return 'base_03'
#----------------------------------------------------------
class base_04(base_03):
        def __str__(self):
		return super(base_04, self).__str__()+' base_04'
#----------------------------------------------------------
if __name__=='__main__':
	#s=base_01(5)
	#print(s)
	#print(s.get())

	b_01=base_01(5)
	b_02=base_02(5)
	assert(isinstance(b_01, base_00))
	assert(isinstance(b_01, base_01))
	assert(isinstance(b_02, base_02))
	#--------------------------------------------------
	b=base_04()
	assert(str(b)=='base_03 base_04')
