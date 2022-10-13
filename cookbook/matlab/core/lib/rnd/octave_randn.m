%returns a random number from the standard normal distribution
%cf normrnd

assert(size(randn(3))==[3 3]);
assert(size(randn(3,3))==[3 3]);
assert(size(randn(3, 4))==[3 4]);

randn(3)

mu=5;
sigma=1;
mu+sigma*randn(3)
