if __name__ == '__main__':

    l = list(range(5))
    assert(list(filter(lambda x: x%2 == 0, l)) == [ 0, 2, 4 ])
    assert(list(filter(lambda x: x%2 != 0, l)) == [ 1, 3 ])
