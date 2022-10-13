#----------------------------------------------------------
#	cumulative average/std dev
#----------------------------------------------------------
var_ <- function(x) #==sd(x)^2
{
	n <- length(x)
	mean <- mean(x)
	sum <- 0
	for(i in 1:n)
	{
		sum <- sum + (x[i]-mean)^2
	}
	return(1/(n-1)*sum)
}
sd_ <- function(x) #==sd(x)
{
	sqrt(x)
}
#----------------------------------------------------------
#http://stackoverflow.com/questions/2765374/efficient-calculation-of-matrix-cumulative-standard-deviation-in-r
cumvar <- function(x)
{
	ind_na <- !is.na(x)
	nn <- cumsum(ind_na)
	x[!ind_na] <- 0
	cumsum(x^2) / (nn-1) - (cumsum(x))^2/(nn-1)/nn
}
cumsd <- function(x)
{
	sqrt(cumvar(x))
}
cumsd_ <- function(x)
{
	n <- length(x)
	ret <- rep(NA, times=rep(n))
	for(i in 2:n)
	{
		ret[i] <- sd(x[1:i])
	}
	return(ret)
}
#----------------------------------------------------------
x <- c(1:5)
mean <- cumsum(x) / seq_along(x)
var <- cumvar(x)
sd <- cumsd(x)

x
mean
sqrt(var)
sd
