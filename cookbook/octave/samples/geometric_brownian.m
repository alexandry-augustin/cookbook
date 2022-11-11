% geometric_brownian(N,r,alpha,T) simulates a geometric Brownian motion 
% on [0,T] using N normally distributed steps and parameters r and alpha

%X=geometric_brownian(1000,1,1,4)

function [X] = geometric_brownian(N,r,alpha,T)

t = (0:1:N)'/N;                   % t is the column vector [0 1/N 2/N ... 1]

W = [0; cumsum(randn(N,1))]/sqrt(N); % S is running sum of N(0,1/N) variables

t = t*T;
W = W*sqrt(T);

Y = (r-(alpha^2)/2)*t + alpha * W;

X = exp(Y);

plot(t,X);          % plot the path
hold on
plot(t,exp(r*t),':');
axis([0 T 0 max(1,exp((r-(alpha^2)/2)*T+2*alpha))])
title([int2str(N) '-step geometric Brownian motion and its mean'])
xlabel(['r = ' num2str(r) ' and alpha = ' num2str(alpha)])
hold off