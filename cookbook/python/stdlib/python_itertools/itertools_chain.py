import itertools

if __name__ == "__main__":
    l1 = ("a", "b")
    l2 = (0, 1)
    c = itertools.chain(l1, l2)
    assert list(c) == ["a", "b", 0, 1]

    # ---

    l = [l1, l2]
    c = itertools.chain.from_iterable(l)
    assert list(c) == ["a", "b", 0, 1]
