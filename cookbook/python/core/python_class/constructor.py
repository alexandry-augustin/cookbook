class base:

    def __init__(self, m):
        self.m = m
    
    def get(self):
        return self.m


if __name__ == '__main__':

    b = base(5)
    assert(b.get() == 5)