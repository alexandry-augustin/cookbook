%returns a pseudorandom scalar drawn from the standard uniform distribution on the open interval (0,1).

assert(size(rand(3))==[3 3]);
assert(size(rand(3,3))==[3 3]);
assert(size(rand(3, 4))==[3 4]);

rand(3, 1)