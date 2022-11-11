%https://www.youtube.com/watch?v=clMbOOz6yR0
%!octave --persist %

% Choose a kernel (covariance function)
kernel=2
switch kernel
	case 1; k=@(x,y) 1*x'*y;	% Linear
	case 2; k=@(x,y) exp(-100*(x-y)'*(x-y)); % Squared exponential
	case 3; k=@(x,y) exp(-1*sqrt((x-y)'*(x-y))); % Ornstein-Uhlenbeck 
end

%sample points
points=(0:.05:1);
[U,V]=meshgrid(points,points);
x=[U(:) V(:)]; %Cartesian product
n=size(x,1); %Cardinality
assert(size(x)==[n 2]);

%covariance matrix
Sigma=zeros(n,n);
for i=1:n 
	for j=1:n
		%assert(size(x(i,:))==[1 2]) %slow things down
		Sigma(i,j)=k(x(i,:)',x(j,:)');
	end
end

%sampling
L=chol(Sigma+1e-6*eye(n));
z=L*randn(n,1);
assert(size(z,2)==1)
Z=reshape(z,size(points, 2),size(points, 2));
%Z=reshape(z,sqrt(n),sqrt(n));
%Z=mvnrnd(0,Sigma)

%plotting
figure(1);
surf(U,V,Z);
