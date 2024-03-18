if __name__ == '__main__':

    l = list(range(5))
    # Return a new list with only even values
    assert(list(filter(lambda x: x%2 == 0, l)) == [ 0, 2, 4 ])
    # Return a new list with only odd values
    assert(list(filter(lambda x: x%2 != 0, l)) == [ 1, 3 ])
