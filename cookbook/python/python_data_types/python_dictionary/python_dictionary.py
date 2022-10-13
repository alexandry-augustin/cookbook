def get_from_path(dic, path):
    """
        access nested dictionay structure using '/'-separated paht
    """
    keys = path.split('/')
    val = dic

    for key in keys:
        val = val.get(key)

    return val

def merge():
    dict1 = {'Name':'abc', 'Age':7}
    dict2 = {'Sex': 'female', 'Age':8}
    dict1.update(dict2)
    assert(len(dict1.keys())==3)
    assert(dict1["Age"]==8)

def misc():
    d={}
    d=dict()
    assert(len(d)==0)
    d = dict()
    assert(len(d)==0)
    #--------------------------------------------------
    #initialization
    keys=['a','b']
    values=0
    d=dict.fromkeys(keys, values)
    assert(d['a']==0)
    assert(d['b']==0)

    values=[0, 1]
    d=dict(zip(keys, values))
    assert(d['a']==0)
    assert(d['b']==1)
    #--------------------------------------------------
    # build dict from 2 lists
    keys=['a', 'b']
    values=[True, False]
    d=dict(zip(keys, values))
    #--------------------------------------------------
    #get values
    d={1:'one', 2:'two'}
    values=d.values()
    assert(values[0]=="one")
    assert(values[1]=="two")
    #--------------------------------------------------
    #check if key exist
    d={1:'one', 2:'two'}
    assert(0 not in d)
    assert(1 in d)
    #--------------------------------------------------
    d={1:'one', 2:'two'}
    d={'a':1, 'b':2}
    d={'ab':['a', 'b'], 'cd':['c', 'd']}
    d={(1, 2, 3):[], ('a', 'b'):[]} #tuples
    #--------------------------------------------------
    str="abc"
    d={}
    for i,c in enumerate(str):
        d[i]=c
    assert(d[0]=='a')
    assert(d[1]=='b')
    assert(d[2]=='c')
    #--------------------------------------------------
    d={1:0, 2:1}
    for k,v in d.iteritems():
        assert(k==v+1)
    #--------------------------------------------------
    #change key values
    d={1:0, 2:1}
    for k,v in d.iteritems():
        d[k-1]=d.pop(k)
    for k,v in d.iteritems():
        assert(k==v)
    #--------------------------------------------------
    #extract keys and values as arrays
    d={1:8, 2:9}
    assert(d.keys()==[1,2])
    assert(d.values()==[8,9]) #python 2
    assert(list(d.values())==[8,9]) # python 3
    assert(d.items()==[(1,8),(2,9)])
    #--------------------------------------------------
    d={8:'a', 9:'b'}
    for i in d:
        print 'd[', i, ']=', d[i]
    #--------------------------------------------------
    #switch/case emulation  
    def switch(x):
         return {
         'a': 1,
         'b': 2,
         }.get(x, 9)    #default if x not found
    assert switch('a')==1
    assert switch('o')==9
    #--------------------------------------------------
    #sum
    d={'a':0, 'b':1, 'c':2}
    assert(sum(d.values())==3) #In Python<3, you may want to use itervalues instead (which does not build a temporary list)
    #--------------------------------------------------
    #sum columns
    n=2
    d={'a':[0,1], 'b':[1,2], 'c':[2,3]}
    cols=[[i[j] for i in d.values()] for j in range(2)]
    assert([sum(i) for i in cols]==[0+1+2, 1+2+3])
    #--------------------------------------------------
    #dict comprehension
    d={'a':0, 'b':1, 'c':2}
    assert({k:v for (k,v) in d.iteritems() if 'b' in k}=={'b':1}) #requires Python 2.7 or greater
    #In Python 3, there is only dict.items(), not iteritems() so you would use:
    #filtered_dict = {k:v for (k,v) in d.items() if filter_string in k}

    keys=['a', 'b', 'c']
    values=[1, 2, 3]
    assert({k:v for (k,v) in zip(keys, values)}=={'a': 1, 'c': 3, 'b': 2}) #Python 3.x
    #--------------------------------------------------
    #zip
    keys=['a', 'b', 'c']
    values=[1, 2, 3]
    assert(dict(zip(keys, values))=={'a': 1, 'c': 3, 'b': 2}) #working for both Python 2.x and 3.x
    #--------------------------------------------------
    d={0:[0,0], 1:[1,1]}
    for k,v in d.iteritems():
        v=[9,9]
    assert(d=={0:[0,0], 1:[1,1]})

    for k,v in d.iteritems():
        d[k]=[9,9]
    assert(d=={0:[9,9], 1:[9,9]})
    #--------------------------------------------------
    d = {'a': {'b':10} }
    assert(get_from_path(d, 'a/b')==10)
    print('Finished')

if __name__=='__main__':
    merge()
    misc()
