BMI<-rnorm(n=1000, m=24.2, sd=2.2) 
X11()
histinfo<-hist(BMI)

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
#-----------------------------------------------------------
# equivalent to np.bincount()
a <- c(1, 1, 2, 2, 2, 3)
num <- hist(a, breaks=seq(0, 3, 1), plot=FALSE)$counts
num
