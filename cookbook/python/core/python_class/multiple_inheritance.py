"""
When the method is overridden in one of the classes
https://www.geeksforgeeks.org/multiple-inheritance-in-python/
"""

class base_00():
    
    def get_id(self):
        return 0
    
class base_01():
    
    def get_id(self):
        return 1

class sub_00(base_00, base_01):
    pass

class sub_01(base_01, base_00):
    pass

if __name__ == '__main__':

    s = sub_00()
    assert(s.get_id() == 0)

    s = sub_01()
    assert(s.get_id() == 1)