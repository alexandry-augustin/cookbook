def ternary_test():
    """
        ternary oprator (a?b:c)
    """
    a=True
    b=False
    assert((a if a==b else b)==b)
    #--------------------------------------------------
    #conditional operator
    #C equivalent: res=(n>10)?true:false;
    n=15
    res=True if n>10 else False #from Python 2.5 onwards 
    value=[True, False][n>10]  

if __name__ == '__main__':

    # TODO checks that the two arguments refer to the same object in memory
    # assert( is )
    # assert( is not )
    #--------------------------------------------------
    assert(1 < 5 and 4 < 10)
    assert(2 < 5 or 9 < 4)
    assert(not(9 < 5))
    #--------------------------------------------------
    ternary_test()
    assert(7%3 == 1)
    assert(2**2==4)
    assert(1e3 == 1000)
    #--------------------------------------------------
    # bitwise operators
    # 
    #   Bitwise AND: &
    #   Bitwise OR: |
    #   Bitwise XOR: ^
    # 
    #   Bitwise NOT: ~
    #   Bit shifts: <<, >>

    assert(bin(15) == '0b1111')
    assert(bin(10) == '0b1010')
    assert(bin(5)  == '0b101')
    assert('0b{0:04b}'.format(5) == '0b0101')

    assert(15^10 == 5)
    # 15 AND 10: 0101
    assert(15&10 == 10)
    # 15 OR 10: 1111
    assert(15|10 == 15)

    # NOT 10: 1010
    # print(~10)
    # assert(~10 == 5)