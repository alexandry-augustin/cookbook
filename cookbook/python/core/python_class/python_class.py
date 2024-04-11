# a class can only have 1 constructor
#----------------------------------------------------------
#class Old1:
#...
#
#class Old2(Old1, UserDict): # Assuming UserDict is still old-style
#...
#----------------------------------------------------------
#class New1(object):
#...
#class New2(New1):
#...
#class New3(Old1, New2):
#...
#class New4(dict, Old1):  # dict is a newstyle class
#...
#----------------------------------------------------------
class base_00(object): #object by default
    n=100   #class variable (static)
    def __init__(self, int):
        print("[base_00::__init__]")
        self.n=int  #instance variable
    def get(self):
        return self.n
    def get_(self):
        return self.z 
    def __str__(self):
        return "[base_00:__str__]"
#----------------------------------------------------------
class base_01:
    def __init__(self):
        self.n=0
#----------------------------------------------------------
class base_02:
    def __init__(self):
        assert(False)
#----------------------------------------------------------
class base_03():
    def __init__(self):
        pass
    def create_and_set_n(self, n):
        self.n=n
#----------------------------------------------------------
class base_05(object):
    def __init__(self):
        print("[base_05::__init__]")
#----------------------------------------------------------
class base_06(base_05):
    def __init__(self):
        super(base_06, self).__init__() #super().__init__ never called automatically
        print("[base_06::__init__]")
#----------------------------------------------------------
if __name__ == '__main__':
    
    b=base_00(5)
    b.n=5
    
    assert(base_00.n==100)

    print(b)
    assert(b.get()==5) #bounded
    assert(base_00.get(b)==5) #unbounded

    #b.f() #will crash
    b.z=6; #member variable declared on the fly
    assert(b.z==6)
    assert(b.get_()==6)

    b=base_02 #nok
    #b=base_02() #ok

    b=base_03()
    assert(not hasattr(b, 'n'))
    b.create_and_set_n(6)
    assert(hasattr(b, 'n'))
    assert(b.n==6)

    b=base_06()
    #--------------------------------------------------
    b=base_01()
    b.n=5
    assert(b.n==5)
