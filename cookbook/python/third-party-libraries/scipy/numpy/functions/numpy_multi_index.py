import numpy as np

if __name__ == '__main__':

    a=np.arange(10, (3*3)+10).reshape((3,3))

    it = np.nditer(a, flags=['multi_index'])
    while not it.finished:
        print "multi_index[0]: %s"%it.multi_index[0]
        print "multi_index[1]: %s"%it.multi_index[1]
        print "value: %s"%a[it.multi_index]
        print "it[0]: %s"%it[0]
        #print "it[1]: %s"%it[1]
        it.iternext()

    a=np.arange(10, (3*3*3)+10).reshape((3,3,3))

    it = np.nditer(a, flags=['multi_index'])
    while not it.finished:
        print "multi_index[0]: %s"%it.multi_index[0]
        print "multi_index[1]: %s"%it.multi_index[1]
        print "multi_index[2]: %s"%it.multi_index[2]
        print "value: %s"%a[it.multi_index]
        print "it[0]: %s"%it[0]
        it.iternext()
