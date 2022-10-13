%https://www.youtube.com/watch?v=clMbOOz6yR0
%!octave --persist %

% Choose a kernel (covariance function)
kernel=2
switch kernel
	case 1; k=@(x,y) 1*x'*y;	% Linear
	case 2; k=@(x,y) exp(-100*(x-y)'*(x-y)); % Squared exponential
	case 3; k=@(x,y) exp(-1*sqrt((x-y)'*(x-y))); % Ornstein-Uhlenbeck 
end

% Choose points at which to sample
points=(0:.05:1)';
[U,V]=meshgrid(points,points);
x=[U(:) V(:)]';
n=size(x,2);

% Construct the covariance matrix
C=zeros(n,n);
for i=1:n
	for j=1:n
		C(i,j)=k(x(:,i),x(:,j));
	end
end

% Sample from the Gaussian process at these points
u=randn(n,1);		% sample u~N(0, I)
[A,S,B]=svd(C);		% factor C=ASB'
z=A*sqrt(S)*u;		% z=AS^(.5)u ~ N(0,C)
assert(size(z,2)==1)

% Plot
figure(2); clf
Z=reshape(z,sqrt(n),sqrt(n));
surf(U,V,Z);
