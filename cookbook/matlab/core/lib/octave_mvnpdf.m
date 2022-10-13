mu=[0 0];
Sigma=[.25 .3;.3 1];
x1=-3:.2:3;
x2=-3:.2:3;
[X1,X2]=meshgrid(x1,x2);
F=mvnpdf([X1(:) X2(:)],mu,Sigma);  % compute Gaussian pdf
F=reshape(F,length(x2),length(x1)); % put into same size as X1, X2

contour(x1,x2,F), axis equal  % set same scale for x and y...
surf(x1,x2,F);