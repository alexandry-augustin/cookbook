%Cholesky decomposition
%'upper' by default

A=[4 12 -16;12 37 -43;-16 -43 98];
L=chol(A,'lower');
L_=chol(A,'upper');
assert(L==[2 0 0;6 1 0;-8 5 3]);
assert(L==L_');
assert(A==L*L_);
