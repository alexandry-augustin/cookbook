%[X,Y] = meshgrid(xgv,ygv)
%[X,Y,Z] = meshgrid(xgv,ygv,zgv)
%[X,Y] = meshgrid(gv)
%[X,Y,Z] = meshgrid(gv)

x1=[1 2 3 4];
x2=[-9 -8 -7];
[X1,X2]=meshgrid(x1,x2);
assert(X1==[1 2 3 4;1 2 3 4;1 2 3 4]);
assert(X2==[[-9 -8 -7]' [-9 -8 -7]' [-9 -8 -7]' [-9 -8 -7]']);

assert([X1(2,3) X2(2,3)]==[3 -8]);
