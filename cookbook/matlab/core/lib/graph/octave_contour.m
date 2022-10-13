%contour map

%axis
x1=-3:.1:3;
x2=-3:.1:3;
[x,y]=meshgrid(x1, x2);

%function
%z=x.^2-y.^2;
addpath('../../octave_fix/')
mu=[0 0];
Sigma=[1 0;0 1];
z=mvnpdf([x(:) y(:)],mu,Sigma);
z=reshape(z,length(x2),length(x1));

%plotting
subplot(2,2,1)
[C,h]=contour(x,y,z,2); %10 lines by default
clabel(C,h)

subplot(2,2,2)
contour3(x,y,z);

subplot(2,2,3)
contourf(x,y,z);
