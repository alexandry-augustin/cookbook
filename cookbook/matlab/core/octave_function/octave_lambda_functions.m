f_00=@(x,y) x+y;
f_01=@(x,y) x*y;

assert(f_00(1,1)==2);
assert(f_01(1,1)==1);
