#No private, public, protected keywords
#All member variables and methods are public by default
#----------------------------------------------------------
#name mangling is used for "private" class members which are designated as such by giving them a name with two leading underscores and no more than one trailing underscore.
#example: __thing will be mangled, as will ___thing and __thing_, but __thing__ and __thing___ will not. 
#----------------------------------------------------------
class base_00:
	var_00   =None # public variable
	_var_01  =None # protected variable
	__var_02 =None # private variable
	def __init__(self, n):
		self.var_00	=n
		self._var_01	=n
		self.__var_02	=n
	def f_00(self):
		return b_00.__var_02==9
#----------------------------------------------------------
if __name__ == '__main__':
	b_00=base_00(9)  

	#public
	assert b_00.var_00==9
	#protected
	assert b_00._var_01==9
	#private
	#assert b_00.__var_02==9 #nok
	assert b_00._base_00__var_02==9
	assert b_00.f_00()
