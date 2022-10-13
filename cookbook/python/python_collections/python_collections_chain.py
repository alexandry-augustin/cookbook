from itertools import chain 

def generator(beg, end):
    for i in range(beg, end):
        yield i


if __name__ == '__main__':
    it_00 = chain(generator(0, 5), generator(10, 15))
    for n in it_00:
        print n

    for n in it_00:
        print n
    for n in it_00:
        print n
