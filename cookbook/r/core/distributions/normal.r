# dnorm: density
# pnorm: distribution function
# qnorm: quantile function
# rnorm: generates random deviates


print(sample(1:10, 10, replace=F))




#dist
x <- dnorm(0, mean=0, sd=1) #height of std normal distribution for x=0
x <- seq(-20, 20, by=.1)
y <- dnorm(x)
#----------------------------------------------------------
#samples
norm <- rnorm(3) #standard normal distribution (with mean 0 and standard deviation 1)
norm
mean(norm)
sd(norm)
