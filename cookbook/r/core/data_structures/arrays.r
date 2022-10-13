#Arrays are similar to matrices but can have more than two dimensions. 
#----------------------------------------------------------
#creation
x <- array(0, dim=c(2,2,2))
x <- seq(1, 5) 
x <- rep(1, times=5)
stopifnot(seq(-2, 2, by=1)==c(-2,-1,0,1,2))
stopifnot(numeric(3)==c(0,0,0))
stopifnot(length(x)==5)

# manip
x <- c(1,2,3)
stopifnot(x+1==c(2,3,4))
stopifnot(mean(x)==2)
stopifnot(length(x)==3)
dim(x)

x <- array(1, dim=c(2,2))
x <- as.vector(x) #reshape to 1 dimension


#assignment
x <- c(1,2,3)
stopifnot(x[2]==2)
x[2:3] <- c(3, 2)
stopifnot(x==c(1,3,2))

#insertion
x <- c(1, 2, 3) 
x[5] <- 5 # Inserts a 5 in the 5th position of the vector, automatically inserting an `NA' values position 4




x <- array(0, dim=c(2,2,2))
x[1, 2, 1] <- 5

x <- array(1, dim=c(2, 2))
diag(x) <- 6
#x[,1]


x <- array(1, dim=c(3, 2, 4)) #(J,L,K)
x[2,1,3] <- 9
print(x)


x <- c(1,4,15,6,7)
print(which.max(x)) #argmax





array(0, dim=c(2,3,4), dimnames=list( d1=c("A1","A2"), d2=c("B1","B2","B3"), d3=c("C1","C2","C3","C4")) ) 
