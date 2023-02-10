import pprint

N=5

def f():
    n=5
    pprint.pprint(locals())

def pprint_test():

#     d = {'a':2, 'b':{'x':3, 'y':{'t1': 4, 't2':5}}}
    d = {'a':2, 'b':5}

    pp = pprint.PrettyPrinter(indent=4, sort_dicts=False)
    pp.pprint(d)

def pformat_test():

    d = {'a':2, 'b':5}

    pp = pprint.PrettyPrinter(indent=4, sort_dicts=False)
    pstr = pp.pformat(d)
    # or
    # pstr = pprint.pformat(d, indent=4, sort_dicts=False)

    print(pstr)

if __name__ == '__main__':

    f()
    
    pprint_test()
    pformat_test()
