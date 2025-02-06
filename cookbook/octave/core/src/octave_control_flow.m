%==	Equal to
%~=	or != Not equal to

%if statement
n=0;
if(n==0) %parenthesis optional
  n=1;
end

a = 4;
b = 4;
if (a<b) & (a==0)
  j = -1;
elseif (a>b)
  j = 2;
else 
  j = 3
end

%for loop
x=[];
for i=1:1:3
  x=[x,i^2];
end
x

%while loop
n=1;
nFactorial=1;
while nFactorial < 1e100
  n=n+1;
  nFactorial=nFactorial*n;
end
%assert(n==factorial(N));