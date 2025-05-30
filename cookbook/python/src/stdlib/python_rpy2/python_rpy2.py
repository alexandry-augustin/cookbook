import rpy2

#ipython module
%load_ext rpy2.ipython
%%R
par(mai = c(1.36, 1.5, 1.093, 0.56))
curve(dnorm, -4, 4, ylab = expression(f[X](x)), cex.lab = 2, cex.axis = 2, lwd= 2) # plot a normal pdf
title("Probability density function", cex.main = 2) # add a title ...
legend("topleft", legend = c(expression(mu == 0), expression(sigma^2 == 1)), cex = 2) # ... and a legend
par(mai = c(1.36, 1.5, 1.093, 0.56))
curve(pnorm, -4, 4, ylab = expression(F[X](x)), cex.lab = 2, cex.axis = 2, lwd= 2) # plot a normal cdf
title("Cummulative distribution function", cex.main = 2)
legend("topleft", legend = c(expression(mu == 0), expression(sigma^2 == 1)), cex = 2)
