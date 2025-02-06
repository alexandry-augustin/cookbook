%=== definition ===
v=[0:2:8]; % or v=0:2:8; %[begin:inc:end], inc default=1
assert(v==[0 2 4 6 8]);
v=0:3; % or v=[0:3];
assert(v==[0 1 2 3]);

v=[0 1 2 3]; % or v=[0,1,2,3];
assert(v==[0 1 2 3]); % or assert(v==[0,1,2,3]);
assert(v(2)==1) %starts a 1

v=v'; %transpose
assert(v==[0;1;2;3]);

v=[];
for i=1:3
    v(i)=i;
end
assert(v==[1 2 3]);

v=[1 2 3];
w=[4 5 6];
assert([v w]==[1 2 3 4 5 6]);
assert([v;w]==[1 2 3;4 5 6]);


% 1 2 3
% 4 5 6
% 7 8 9 
A=[1 2 3; 4 5 6; 7 8 9];
B=[[1 4 7]' [2 5 8]' [3 6 9]'];
assert(A==B);
assert(A(1,1)==1); %starts a 1

assert(A(4)==2);
n=4;
%index = x + (y * width)
%x=index % width
%y=index/width 
assert(A(n)==A(mod(n,size(A)(1)),fix((n-1)/size(A)(1))+1));

%=== SubmatrixColon notation ===		http://www.math.ufl.edu/help/matlab-tutorial/matlab-tutorial.html
A=[1 2 3; 4 5 6; 7 8 9];
assert(A(:)==[1;4;7;2;5;8;3;6;9]);
assert(A(:)==[A(:,1);A(:,2);A(:,3)]); %column vector of all elements
assert(A(:,:)==A);
assert(A(2,:)==[4 5 6]); %second row	
assert(A(:,2)==[2;5;8]); %second column
assert(A(2:3,:)==[4 5 6; 7 8 9]); %all rows between 2 to 3 included
%x([2 4], :) %?	
assert(A(:,2:3)==[2 3;5 6;8 9]); %all rows between 2 to 3 included

%=== Random Matrix ===
%rand(n)=rand(n, n) or rand(m, n) % create an nxn matrix with randomly generated entries distributed uniformly between 0 and 1

%randint(m,n)	%rand integers
%randn(n)	%normaly distributed
	
%magic(n)	%magic square
%hilb(n)	%create nxn Hilbert Matrix

%=== Identity Matrix ===
%eye(n)
%eye(n,m)
%eye(size(A))

%=== Other Matrix	 ===
%zeros(n)=zeros(n,n) or zeros(m,n)
%ones(n) or ones(n,m)
%diag(n)	%vector of the diagonal
%diag(diag(n))	%diagonal matrix
%triu	%upper triangle part of a matrix
%tril	%lower triangle part of a matrix
