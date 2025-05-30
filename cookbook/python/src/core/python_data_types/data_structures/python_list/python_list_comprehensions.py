if __name__ == '__main__':
    
    # [expression(i) for i in old_list if filter(i)]
    #
    # { w | w \in V and p(w) }
    # [w for w in V if p(w)]
    
    l = [ 0 for i in range(3) ]
    assert(l == [ 0, 0, 0 ])

    l = [ i**2 for i in range(3) ]
    l = [ (lambda x: x*x)(i) for i in range(3) ]
    assert(l == [ 0, 1, 4 ])

    l = [ i for i in range(7) if i%2==0 ]
    assert(l == [ 0, 2, 4, 6 ])

    l = [ [ j for j in range(3) ] for i in range(2) ]
    assert(l == [ [0, 1, 2], [0, 1, 2] ])

    l = [ [ i+j for i in range(2) ] for j in range(2) ]
    assert(l == [ [0, 1], [1, 2] ])

    # 'unzip' list
    a = [ (1,3), (5,4) ]
    l = [ i for sub in a for i in sub ]
    assert(l == [ 1, 3, 5, 4 ])