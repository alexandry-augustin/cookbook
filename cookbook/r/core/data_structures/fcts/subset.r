#x <- matrix( 
#	c(1, 2, 3, 4, 5, 6), 
#	nrow=3, 
#	ncol=2)

a <- c(1,2,3,4)
b <- c("red", "white", "red", NA)
c <- c(FALSE, TRUE, TRUE, TRUE)
data <- data.frame(a,b,c)

data[ which(data$a>2 & data$c==TRUE), ]
