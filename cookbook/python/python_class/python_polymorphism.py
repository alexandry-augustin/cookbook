class base_00:
    def f(self):              # Abstract method, defined by convention only
        raise NotImplementedError("Subclass must implement abstract method")

class base_01(base_00):
    def f(self):
        return 1

class base_02(base_00):
    def f(self):
        return 2
#----------------------------------------------------------
class base_03(object): 
	def f(self):
		return 3

class base_04(object): 
	def f(self):
		return 4

def f_00(obj):
	return obj.f()
#----------------------------------------------------------
if __name__=='__main__':
	l=[base_01(), base_02()]

	assert(l[0].f()==1)
	assert(l[1].f()==2)

	assert(isinstance(l[0], base_01))
	assert(isinstance(l[1], base_02))
	#--------------------------------------------------
	b_00=base_03()
	b_01=base_04()
	assert(f_00(b_00)==3)
	assert(f_00(b_01)==4)
