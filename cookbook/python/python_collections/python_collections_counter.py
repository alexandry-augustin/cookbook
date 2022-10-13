from collections import Counter
#----------------------------------------------------------
if __name__=='__main__':
    a=["a","b","c","d","a","c"]
    #a=[1,2,3,4,1,3]
    c=Counter(a)
    print c.items()
    print c.keys()

    print sorted(c.items(), key=lambda x: (-x[1], x[0]))
