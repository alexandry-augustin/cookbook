if __name__ == '__main__':

    l = list(range(5))
    assert(list(map(lambda x: x**2, l)) == [0, 1, 4, 9, 16])

    l=[[0, 4], [1, 8], [2, 6]]
    assert(list(map(max, l)) == [4, 8, 6])
    assert([max(i) for i in l] == [4, 8, 6])
