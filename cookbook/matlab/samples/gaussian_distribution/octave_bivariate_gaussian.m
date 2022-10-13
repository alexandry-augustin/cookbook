%mu=[0 0];
%Sigma=[.25 .3;.3 1];
%x1=-3:.2:3;
%x2=-3:.2:3;
%[X1,X2]=meshgrid(x1,x2);
%F=mvnpdf([X1(:) X2(:)],mu,Sigma);  % compute Gaussian pdf
%F=reshape(F,length(x2),length(x1)); % put into same size as X1, X2

%contour(x1,x2,F), axis equal  % set same scale for x and y...
%surf(x1,x2,F);
%%%%%%%%%%%%%%
n=1500;
x1=randn(1,n);
x2=randn(1,n);
plot(x1,x2,'.');
%%%%%%%%%%%%%%
%rho=0.9; z=rho*x1+sqrt(1-rho^2)*x2; plot(x1,z,'.')
rho=0.9;
z=rho*x1+sqrt(1-rho^2)*x2;
plot(x1,z,'.');
%%%%%%%%%%%%%%%%%%%%%%
%http://uk.mathworks.com/help/matlab/ref/randn.html
n=100;
mu=[0 0];
Sigma=[1 .8;.8 1];
U=chol(Sigma);
X=repmat(mu,n,1)+randn(n,2)*U;
plot(X(:,1),X(:,2),'+');
%%%%%%%%%%%%%%
%http://stats.stackexchange.com/questions/26219/generating-a-gaussian-dataset-in-matlab
%dataset includes a total of 800 results drawn randomly from four two-dimensional Gaussian classes with means (−3,0)′, (0,0)′, (3,0)′, and (6,0)′, all with the same variance-covariance matrix
n=800;
mu = 3*floor(rand(1,n)*4) - 3; % x in (-3,0,3,6)
mu = [mu; zeros(1,n)]; % y=0
Sigma = [.5 .05; .05 .5];
L=chol(Sigma); 
X=mu+L'*randn(2,n);
plot(X(1,:),X(2,:),'+');
%%%%%%%%%%%%%%
%using svd
n=100;
mu=[0;0];
Sigma=[1 .8;.8 1];
[U,D,V]=svd(Sigma);
X=(U*sqrt(D))*randn(2,n)+mu*ones(1,n);
plot(X(1,:),X(2,:),'+');
