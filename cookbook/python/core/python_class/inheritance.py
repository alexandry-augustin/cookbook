class base(object):
    
    def __init__(self, id_):
        self.id = id_
        
    def get_id(self):
        return self.id

class sub(base):
    
    def __init__(self):
        base.__init__(self, 9)
        
    def f(self):
        return self.id

if __name__ == '__main__':

    s = sub()
    
    print(s.get_id())
    print(s.f())