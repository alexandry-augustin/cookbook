%adapted from https://www.youtube.com/watch?v=clMbOOz6yR0
%!octave --persist %

clf;

kernel=4
switch kernel
	case 0; k=@(x,y) 1*(x==y);  		%gaussian noise (\sigma^2=1)
	case 1; k=@(x,y) 1*x'*y;		%linear
	case 2; k=@(x,y) 1*min(x,y);		%brownian motion
	case 3; k=@(x,y) 2*(min(x,y)-x*y);	%brownian bridge
	case 4; k=@(x,y) exp(-100*(x-y)'*(x-y)); %squared exponential
	case 5; k=@(x,y) exp(-1*sqrt((x-y)'*(x-y))); %ornstein-uhlenbeck 
	case 6; k=@(x,y) exp(-1*sin(5*pi*(x-y))^2); %periodic
	case 7; k=@(x,y) exp(-100*min(abs(x-y),abs(x+y))^2); %symmetric wrt y
end

% Choose points at which to sample
x=(0:.005:1);
n=length(x);

% Construct the covariance matrix
Sigma=zeros(n,n);
for i=1:n
	for j=1:n
		Sigma(i,j)=k(x(i),x(j));
	end
end

for i=1:3
	% Sample from the Gaussian process at these points
	[A,S,B]=svd(Sigma);		% factor C=ASB'
	z=A*sqrt(S)*randn(n,1);

	figure(1);
	hold on;
	plot(x,z,'-')
	axis([0,1,-2,2])
end
