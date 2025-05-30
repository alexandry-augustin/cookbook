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
    
    ternary_test()