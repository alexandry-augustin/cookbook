# strings are immutable
# "" and '' are interchangeable
#----------------------------------------------------------
import math
#----------------------------------------------------------
class base_00(object):
    def __str__(self):
        return "base_00" #self.__name__
#----------------------------------------------------------
def unicode():
	str=u"\u00B1" #+/- UTF-16
	print (str)
#----------------------------------------------------------
def misc():
	str="test"+\
		"test"
	assert(str=="testtest")

	str="test\n\tstring"
	str='test\n\tstring'

	str="""test
		string"""
	assert(str=="test\n		string")
	str='''test
		string'''
	assert(str=="test\n		string")

	str="test\
 string"
	assert(str=="test string")
	#--------------------------------------------------
	str="one"
	str+="z"
	assert str=="onez"

	assert len("abc")==3

	assert "one"=="one"
	assert "one"[1]=="n"

	assert "_one_two_".find("two")==5
	assert "_one_two_".find("three")==-1
	assert "_one_two_".index("two")==5
	try:
		"_one_two_".index("three")
	except:
		pass
	assert "_one_two_".rfind("o")==7
	assert "_one_two_".rindex("o")==7
	assert "_one_two_".replace("two", "one")=="_one_one_"
	assert "_one_two_".replace("o", "?")=="_?ne_tw?_"
	assert "_one_two_".replace("o", "?", 1)=="_?ne_two_"
	assert "_one_two_".endswith("o_")==True
	assert "_one_two_".startswith("_o")==True
	assert "_one_two_".rstrip("_")=="_one_two"
	assert "_one_two_".lstrip("_")=="one_two_"
	assert "_one_two_".strip("_")=="one_two"
	assert "_one_two_".strip("_o")=="ne_tw"

	assert "_one".ljust(8, ".")=="_one...." #default: " "
	assert "_one".ljust(2, ".")=="_one"
	assert "_one"[0:2].ljust(8, ".")=="_o......"
	assert "two_".rjust(8, ".")=="....two_"
	#center
	assert "1".zfill(4)=="0001"
	assert '_{}_{}_'.format('one', 'two')=="_one_two_"
	assert "123".isdigit()==True
#	assert "_one_".isalpha()==True

	assert eval("pi*r*r", {"pi":3.14}, {"r":5})==78.5 #returns some value
	exec("for i in [1,2,3]: assert i<4") #returns nothing
	#compile("assert(True)", "", "exec")

	str=""
	assert not str
	if not str:
		assert len(str)==0
	else:
		assert len(str)>0

	assert("a1a2a3bc".count("a")==3)
#----------------------------------------------------------
def case():
	"""
		capitalisation
	"""
	assert "oNe".upper()=="ONE"
	assert "oNe".lower()=="one"
	assert "oNe".swapcase()=="OnE"
	assert "oNe".capitalize()=="One"
#	assert "ONE".isupper==True
#	assert "one".islower==True
#----------------------------------------------------------
def split():
	"""
		tokenise: string to list
	"""
	assert "_one_two_".split("_")==["", "one", "two", ""]
	assert "_one__two_".split("_")==["", "one", "", "two", ""]
	assert "\none\ntwo\n".splitlines()==["", "one", "two"]
	assert "\none\ntwo\n".splitlines(1)==["\n", "one\n", "two\n"]
#----------------------------------------------------------
def join():
	"""
		list to string
	"""
	assert "one"+"two"=="onetwo"
	assert "_".join("one")=="o_n_e"
	assert "_".join(["one", "two"])=="one_two"
	assert 4*"a"=="aaaa"
#----------------------------------------------------------
def formating():
	# old style
	assert "%s_%s_%d"%("one", "two", 5)=="one_two_5"
#TODO	assert "%s_%i %i %0.2f" % ("abc",1,2,math.pi)==""
	#--------------------------------------------------
	# new style
	print "Username {0}".format('luispedro')
	print "Username {}".format('luispedro')
	print "Username {0} (last login: {1})".format('luispedro', 'yesterday')
	print "Username {} (last login: {})".format('luispedro', 'yesterday')
	#--------------------------------------------------
#----------------------------------------------------------
def redefinition():
	str="abc"
	str=str(5)
#----------------------------------------------------------
def convertion():
	#int to ascii
	assert chr(35)=="#"

	#whatever to string
	data=5
	assert data==5
	assert data!="5"
	data=str(data)
	assert data!=5
	assert data=="5"
#----------------------------------------------------------
def substring():
	#out of bound is okay
	str="abc"
	assert str[-5:10] == str
#----------------------------------------------------------
def string_builder():
	"""
		string are immutable objects
	"""
	l=["abc", 123]

	str_builder=""
	for data in l:
		str_builder += str(data) # !!! inefficient
	assert(str_builder=="abc123")

	builder_list=[]
	for data in l:
		builder_list.append(str(data))
	str_builder="".join(builder_list)
	# or
	str_builder="".join([str(data) for data in l])

	assert(str_builder=="abc123")
#----------------------------------------------------------
def misc():

	#print "n="+5 #nok
	str_00="n="+'5'
	assert(str_00=="n=5")

	n_00="12345"
	assert(len(n_00)==5)
#----------------------------------------------------------
if __name__ == '__main__':
	convertion()
	substring()
	misc()
	#redefinition()
	assert(str(base_00())=="base_00")
	unicode()
	formating()
	split()
	join()
	string_builder()
	case()
	misc()