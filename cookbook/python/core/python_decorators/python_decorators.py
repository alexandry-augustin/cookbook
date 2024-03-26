import time

# ---

def timer(func):
    def wrapper():

        start = time.time()
        func()
        end = time.time()
        print("Elapsed time:", end-start, "seconds")

    return wrapper

@timer
def run():
    time.sleep(2)

# ---

def f(func):
    def wrapper(*args, **kwargs):
        
        print('before')
        ret = func(*args, **kwargs)
        print('after')

        return ret

    return wrapper

@f
def add(x, y):
    return x + y

# ---

if __name__ == '__main__':

    run()
    print(add(2, 5))