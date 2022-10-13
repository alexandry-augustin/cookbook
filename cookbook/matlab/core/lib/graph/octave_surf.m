%3-D shaded surface plot

[X,Y] = meshgrid(-8:.5:8);

R=sqrt(X.^2 + Y.^2) + eps;
Z=sin(R)./R;

sigma=1
Z=exp(-X.^2/(2*sigma^2)-Y.^2/(2*sigma^2));
Z=Z./sum(Z(:));

mesh(X,Y,Z)
