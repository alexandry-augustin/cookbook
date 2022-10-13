x <- rnorm(10)
y <- rnorm(10)
xy <- data.frame(x,y)
#----------------------------------------------------------
filename="out.r"
#----------------------------------------------------------
#xy

#dump("xy", file=filename, append=FALSE)
##rm(xy)
#
#source(file=filename)
#xy
#
#if(file.exists(filename))
#	file.remove(filename)
#----------------------------------------------------------
x
y
cat("-----------------------\n")

dump(c("x", "y"), file=filename, append=FALSE)
rm(x)
rm(y)

source(file=filename)
x
y

if(file.exists(filename))
	file.remove(filename)
