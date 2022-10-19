import numpy as np

# vectorizes all input parameters of a function
#---------------------------------------------------------
def add_one(a):
    return a+1

v_add_one = np.vectorize(add_one)
a = v_add_one(1)
b = v_add_one(range(4))
#---------------------------------------------------------
def plus(a, b):
    return a+b

vplus = np.vectorize(plus)
a = vplus(range(4), 2)
b = vplus(2, range(4))
c = vplus([2]*4, range(4))
d = vplus(range(4), [2]*4)
assert(np.equal(np.equal(a, b), np.equal(c, d)).all())
#---------------------------------------------------------
def leq(a, b):
    return a >= b

vleq = np.vectorize(leq)
print(vleq(range(4), 2))
print(vleq(2, range(4)))
print(vleq(range(4), range(4)))
