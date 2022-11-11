mu = 0;
sigma=1

%density
x = (-5 * sigma:0.01:5 * sigma) + mu;  %// Plotting range
y = exp(- 0.5 * ((x - mu) / sigma) .^ 2) / (sigma * sqrt(2 * pi));

plot(x, y)
%line([mu-sigma mu-sigma],[0 1])
%line([mu+sigma mu+sigma],[0 1])

%samples
%r=normrnd(mu,sigma); 
%hold on
%hist(r,20)


%or
%R = normrnd(mu,sigma)
%normplot(R)
