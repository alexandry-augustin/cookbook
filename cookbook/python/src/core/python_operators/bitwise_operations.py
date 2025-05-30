if __name__ == '__main__': 

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