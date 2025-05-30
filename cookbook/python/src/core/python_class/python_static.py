# See also @classmethod
# https://stackoverflow.com/questions/12179271/meaning-of-classmethod-and-staticmethod-for-beginner

class base:

    def __init__(self, n):

        self.n = n
    
    def get(self):
        return self.n

    @staticmethod
    def add(a, b):
        return a+b


if __name__ == '__main__':

    b = base(4)
    assert(b.get() == 4)

    assert(base.add(1, 2) == 3)