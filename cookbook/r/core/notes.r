### functions
x <- sqrt(2*2)
stopifnot(typeof(x)=="double")
x <- abs(-2)
#t(x) #transpose

#ls() #list of defined variables
#stop("Message") #sys.exit()
#warning("Message")
#source("script.r")

#R.Version()
#rm(list = ls()) #clear workspace
#getwd() #get working directory
#setwd("path") #set working directory



x <- c(1:3)
y <- x #copy by value
x[1]=5
x
y


#array equality
x <- array(6:9)
y <-array(6:9)
all(x==y)
