class base_00(object):
    def __init__(self, n=0):
        self.n=n
#----------------------------------------------------------
if __name__ == '__main__':

    #empty list
    l=list()
    assert(len(l)==0)
    l=[]
    #l[4]=4 # nok
    assert(len(l)==0)
    l=[[] for i in range(2)] # multidimentional array
    #--------------------------------------------------
    # pre-allocation
    l=10*[0]
    #--------------------------------------------------
    l=[0, 1, 2]
    assert(l[1]==1)
    l=[[0, 0], [1, 1], [2, 2]]
    assert(l[1]==[1, 1])
    #--------------------------------------------------
    assert(len(range(3))         == 3)
    assert(list(range(3))        == [0, 1, 2])
    assert(list(range(5, 10))    == [5, 6, 7, 8, 9])
    assert(list(range(5, 10, 2)) == [5, 7, 9])
    assert(list(range(3))        == [0, 1, 2]) #always starts at 0
    l=range(3)
    assert(l[0]==l.index(0))
    #--------------------------------------------------
    # swapping elts
    l=[0, 1]
    l[1], l[0] = l[0], l[1]
    assert(l==[1, 0])
    #--------------------------------------------------
    #list comprehensions
    #[expression(i) for i in old_list if filter(i)]
    #
    # { w | w \in V and p(w) }
    # [w for w in V if p(w)]
    #
    l=[0 for i in range(3)]
    assert(l==[0, 0, 0])

    l=[i**2 for i in range(3)]
    l=[(lambda x: x*x)(i) for i in range(3)]
    assert(l==[0, 1, 4])

    l=[i for i in range(7) if i%2==0]
    assert(l==[0, 2, 4, 6])

    l=[[j for j in range(3)] for i in range(2)]
    assert(l==[[0, 1, 2], [0, 1, 2]])

    l=[[i+j for i in range(2)] for j in range(2)]
    assert(l==[[0, 1], [1, 2]])

    #'unzip' array
    a=[(1,3),(5,4)]
    l=[i for sub in a for i in sub]
    assert(l==[1, 3, 5, 4])
    #--------------------------------------------------
    l=[1, 2]
    l.insert(2, 3)
    l.insert(0, 0)
    assert(l==[0, 1, 2, 3])
    #--------------------------------------------------
    #delete item for given index
    l=[0, 1, 2]
    del l[1]
    assert(l==[0, 2])
    #--------------------------------------------------
    #ignore item for index
    l=[0, 1, 2]
    i=1
    l=l[:i]+l[i+1:]
    assert(l==[0, 2])
    #--------------------------------------------------
    # slicing
    l=list(range(10))
    assert(l[0:5]   == [0, 1, 2, 3, 4])
    assert(l[4:7]   == [4, 5, 6])
    assert(l[:5]    == [0, 1, 2, 3, 4])
    assert(l[5:]    == [5, 6, 7, 8, 9])
    assert(l[:]     == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    assert(l[15:20] == list())
    assert(l[8:10]  == [8,9])
    assert(l[8:10]  == [8,9])

    #l=[[i+j for j in range(2)] for i in range(2)]
    #assert(l==[[0,1],[1,2]])
    l=[[0,1],[2,3]]
    assert(l[:][0]==[0,1])
    assert(l[0][:]==[0,1])
    #--------------------------------------------------
    #for l in list:
    #   print(l),
    #for i in range(len(l)):
    #   print(l[i]),
    #--------------------------------------------------
    l=list(range(10))
    i=l  #reference
    i[5]=9
    assert(i[5]==9)
    assert(l[5]==9)
    l[5]=5
    #--------------------------------------------------
    l=list(range(10))
    i=l[:]  #copy
    i[5]=9
    assert(i[5]==9)
    assert(l[5]==5)
    #--------------------------------------------------
    #sort in place
    # l=[1, "two", [1, 2, 3]]   #[1, 'two', [1, 2, 3]]
    # assert(l[2]==[1, 2, 3])
    # l.append(5)       #[1, 'two', [1, 2, 3], 5]
    # l.sort()      #[1, 5, [1, 2, 3], 'two']
    # l=l+l         #[1, 5, [1, 2, 3], 'two', 1, 5, [1, 2, 3], 'two']
    #--------------------------------------------------
    #sort not in place
    l=list(range(2, -1, -1))
    i=sorted(l)
    assert(l==list(range(2, -1, -1)))
    assert(i==list(range(0,3)))
    #--------------------------------------------------
    #append
    l=[1, 2]
    l+=[3, 4]
    assert(l==[1, 2, 3, 4])
    #--------------------------------------------------
    #append
    l=[0, 1]
    l.append(2)
    assert(l==[0, 1, 2])
    #--------------------------------------------------
    #extend
    l=[0]
    l.append([1, 2])
    assert(l==[0, [1, 2]])


    l=[0]
    l.extend([1, 2])
    assert(l==[0, 1, 2])
    #--------------------------------------------------
    #reverse
    l=[1, 2, 3, 4]
    l.reverse()
    assert(l==[4, 3, 2, 1])
    #--------------------------------------------------
    # find elt in a list
    #index(obj): returns the lowest index in list that obj appears
    l=['0', '1', '1', '2'];
    assert(l.index('1')==1)
    assert(l.index('2')==3)
    try:
        l.index('3')
    except:
        pass
    #--------------------------------------------------
    #list arithmetic
    l=[0,1]
    assert(l+l==[0,1,0,1])
    assert(l*2==[0,1,0,1])

    l=[[0]*2]*4
    assert(l==[[0,0], [0,0], [0,0], [0,0]])
    #--------------------------------------------------
    #multidimensional list
    l=[[0,1], [2,3]]
    assert(l[0][0] == 0)
    assert(l[0][1] == 1)
    assert(l[1][0] == 2)
    assert(l[1][1] == 3)
    #--------------------------------------------------
    #max
    l=[0,3,2,1]
    assert(max(l)==3)
    #--------------------------------------------------
    #sum
    l=[0,1,2]
    assert(sum(l)==3)
    #--------------------------------------------------
    #extract column
    cols=[0 ,2]
    l=[[0, 1, 3], [4, 5, 6], [7, 8, 9]]
    assert([[i[j] for i in l] for j in range(3)]==[[0, 4, 7], [1, 5, 8], [3, 6, 9]])
    #assert([[l_[i] for i in cols] for l_ in l]==[[0, 3], [4, 6], [7, 9]])
    #--------------------------------------------------
    #sort
    l=[1, 2, 0]
    l.sort()
    assert(l==[0, 1, 2])

    l=[1, 2, 0]
    m=sorted(l)
    assert(l==[1, 2, 0])
    assert(m==[0, 1, 2])


    l=[base_00(1), base_00(2), base_00(0)]
    m=sorted(l, key=lambda x: x.n)
    assert(m[0].n==0)
    assert(m[1].n==1)
    assert(m[2].n==2)
    #--------------------------------------------------
    #substract 2 arrays
    l=[0, 4]
    m=[1, 8]
    assert([a-b for a,b in zip(l, m)]==[-1, -4])
    #--------------------------------------------------
    #remove by value
    l=list(range(5,10))
    l.remove(7) #remove item with value 7
    assert(l==[5,6,8,9])

        
    # remove by index
    l=list(range(5,10))
    del l[2]
    assert(l==[5,6,8,9])
    #--------------------------------------------------
    l=['a','b','c']
    assert(''.join(l)=="abc")
    #--------------------------------------------------
#   l=['a',0,0,'b',0,0,'c']
#   j=0
#   for i in range(len(l)):
#       if(i%3)
#           l[j]=
    #--------------------------------------------------
    #search and replace
    l=['a','b','b']
    l=['c' if x=='b' else x for x in l]
    assert(l == ['a', 'c', 'c'])
    #--------------------------------------------------
    #list from set
    s=set([0,1])
    l=list(s)
