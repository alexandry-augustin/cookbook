#qplot() quick plot
#----------------------------------------------------------
library(ggplot2)
library(reshape2)
#----------------------------------------------------------
set.seed(0)
#----------------------------------------------------------
#data <- airquality[,1:4]
#X11()
#qplot(x=Var1, y=Var2, data=melt(cor(data, use="p")), fill=value, geom="tile") +
#   scale_fill_gradient2(limits=c(-1, 1))
#----------------------------------------------------------
#x <- 0:10
#y_1 <- x^2
#y_2 <- x^3
#frame <- data.frame(x, y_1, y_2)
#
#X11()
#qplot(data=frame, x=x, y=y_2, geom=c("point", "line")
#	, main="Title", xlab="x", ylab="y"
#	)
#----------------------------------------------------------
x <- 0:9
y <- rnorm(10)
data <- data.frame(x,y)

#stats <- summarySE(data, measurevar="len", groupvars=c("supp","dose"))

X11()
qplot(data=frame, x=x, y=y, geom="line")
#----------------------------------------------------------
message("Press Return To Continue")
invisible(readLines("stdin", n=1))
