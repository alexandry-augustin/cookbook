# same as Arrays but of of dimension 2
#----------------------------------------------------------
x <- matrix( 
	c(1, 2, 3, 4, 5, 6), 
	nrow=3, 
	ncol=2)

#combining matrices
x <- matrix(1:4, 2 ,2)
x <- cbind(x, c(5,6))
x <- rbind(x, c(7,8,9))




m <- matrix(1:4,2,2)
as.vector(m)
as.vector(t(m))

g<-c(c(1,2),c(3,9))
