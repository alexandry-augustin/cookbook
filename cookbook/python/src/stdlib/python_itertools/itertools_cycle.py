import itertools

if __name__ == "__main__":
    l = ("a", "b", "c")
    letters = itertools.cycle(l)
    for i in range(5):
        assert next(letters) == l[i % len(l)]
    # print(len(letters))
