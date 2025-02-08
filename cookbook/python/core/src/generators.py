# - When called, it returns an object (iterator) but does not start execution immediately.
# - Once the function yields, the function is paused and the control is transferred to the caller.
# - Local variables and their states are remembered between successive calls.
# - When the function terminates, StopIteration is raised automatically on further calls.
# - a generator object can be iterated only once. To restart the process we need to create another generator object
# - > "In Python 3 `return value` inside a generator is actually a syntactic sugar for raise `StopIteration(value)`, which is also supported by the `yield from` clause" -- https://stackoverflow.com/questions/28806583/is-it-good-practice-to-mix-yield-and-return-statements-in-python

def f():
    """
        even numbers
    """
    n = 0
    while True:
        yield n
        n += 2

def f():

    n = yield 10 # return value

def f():
    
    n=0
    yield n
    
    n+=1

def f():
    
    print('first')
    yield 0
    
    print('second')
    yield 1

def f():
    
    n = 1
    print('First')
    yield n

    n += 1
    print('Second')
    yield n

    n += 1
    print('Last')
    yield n

def f():
    """
        https://stackoverflow.com/questions/10695456/what-is-the-result-of-a-yield-expression-in-python
    """
    
    i=0
    while True:
        x = yield i
        print('received: {}'.format(x))
        i+=1

if __name__ == '__main__':
    
    # ----------
    # Generators
    # ----------

    generator = f()

    # generator.__next__()
    # or
    next(generator)

    # generator.send('test')
    # generator.send(5)


    b = []

    # b.append(next(g))
    # b.append(next(g))
    # b.append(next(g))
    # next(g)

    for e in f():
        b.append(e)

    # --------------------
    # Generator Expression
    # --------------------
    # - Similar to the lambda functions which create anonymous functions, generator expressions create anonymous generator functions.
    # - The syntax for generator expression is similar to that of a list comprehension in Python. But the square brackets are replaced with round parentheses.

    a = [ 1, 3, 6, 10 ]
    generator = (e**2 for e in a)