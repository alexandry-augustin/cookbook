%remainder
%same as mod(a,b)

a=randi(9);
b=randi(9);
assert(rem(a,b)==mod(a,b));