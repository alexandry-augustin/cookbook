class base():

    def __init__(self, n=0):
        self.n = n

    class sub():
        
        def __init__(self, m=0):
            self.m = m

class Outer(object):
    """
    Factory method to access outer class from an inner class
    https://stackoverflow.com/questions/2024566/how-to-access-outer-class-from-an-inner-class
    """
    def createInner(self):
        return Outer.Inner(self)
    n=9

    class Inner(object):

        def __init__(self, outer_instance):
            self.outer_instance = outer_instance

if __name__ == '__main__':
    
    b = base()
    i = base.sub()

    assert(b.n == 0)
    assert(i.m == 0)

    outer = Outer()
    inner = outer.createInner()
    print(inner.outer_instance.n)

