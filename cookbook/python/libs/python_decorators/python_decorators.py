# https://realpython.com/primer-on-python-decorators/

import functools

def my_decorator(func):
    
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        
        print('Before')
        ret = func(*args, **kwargs)
        print('After')
        
        return ret
    
    return wrapper

@my_decorator
def f_00():
    print("text")
    
@my_decorator
def f_01(text):
    print(text)
    return 'OK'

class my_class(object):
    
    def __init__(self, config):
        pass
    
    def my_decorator(self, func):
        
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            
            print('Before')
            ret = func(*args, **kwargs)
            print('After')
            
            return ret
            
        return wrapper
    
    @my_decorator
    def f_00(self):
        print('text')

if __name__ == '__main__':

    f_00()

    f_01('some text')