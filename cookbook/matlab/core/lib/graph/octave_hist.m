%histogram

%single column
v=rand(20, 1);
%hist(v)
hist(v,50) %number of bins (default=10)

%multiple columns
v=rand(20, 2);
hist(v,10)