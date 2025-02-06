%x = b/A	%solution of xA=b
%x = A\b	%solution of Ax=b

%Element-wise multiplication
%times(A,B) same as A.*B, but is rarely used. It enables operator overloading for classes.
v=[1 2 3];
w=v.*2;
assert(w=[1 4 6]);

v=[1 2 3];
w=[2 4 6];
w=v.*w;
assert(w=[2 8 18]);

assert(2*2*2==2^3);