%normal probability density function
%normpdf(X,MU,SIGMA)
%normpdf(X,MU)
%normpdf(X)
%defaults: mu=0, sigma=1

f_00=@(x, mu, sigma) 1/(sigma*sqrt(2*pi))*exp(-0.5*((x-mu)/sigma)^2);

mu=0;
sigma=1;
x=0;
assert(normpdf(x)==f_00(x, mu, sigma));

v=[-3:1:3];
normpdf(v);
assert(normpdf(v)(4)==f_00(x, mu, sigma));
