"""
    like regular tuple, named tuples are immutable

    typename:
    Point=namedtuple('whatsmypurpose',['x','y'], verbose=True)

    namedtuple() is a factory function for tuples. Here, whatsmypurpose is the type name. When you create a named tuple, a class with this name (whatsmypurpose) gets created internally.
    You can notice this by using the verbose argument like:
        Point=namedtuple('whatsmypurpose',['x','y'], verbose=True)
    Also you can try type(p) to verify this.
"""
from collections import namedtuple

if __name__=="__main__":
    point = namedtuple("point_", "id x y z")

    p=point("center_", 1.0, 2.0, 0.0)
    p=point(id="center", x=1.0, y=2.0, z=0.0)

#    p.z=5 #named tuples are immutable

    assert(p.id=="center")
    assert(p.y==2.0)

    #to dictionary
    d=p._asdict()
    assert(d["id"]=="center")
    assert(d["x"]==1.0)

    # normal iteration over tuples
    for i in p:
        print i

    for name, value in p._asdict().iteritems():
        print(name, value)

    # ... not very usefull
#    for field in p._fields:
#        print(field, field)
