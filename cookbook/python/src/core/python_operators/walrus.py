if __name__ == '__main__': 

    n = 0
    assert(n :=1 == 1)
    assert(n == 1)

    # ---

    a = range(3)
    if n := len(a) < 3:
        assert(n == 3)