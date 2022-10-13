library(ggplot2)
#----------------------------------------------------------
set.seed(0)
#----------------------------------------------------------
x <- 0:100
y <- rnorm(length(x))
data <- data.frame(x,y)
#----------------------------------------------------------
X11()

#p <- ggplot(data, aes(x=x, y=y))
##p <- p+layer(geom="point")
#p <- p+geom_point()
##p <- p+layer(geom="line")
#p <- p+geom_line()
##p <- p+stat_smooth(method="lm")
#p <- p+stat_summary(fun.y=sd, fun.ymin=min, fun.ymax=max) #mean
#p
##summary(p)

#ggplot(data, aes(x=x, y=y)) +
#	ggtitle("Title") +
#	geom_line() +
#	stat_summary(fun.y=mean, colour="blue", geom="line")

#ggplot(data) +
#	geom_line(aes(x=x, y=y))

#uci <- function(y,.alpha){mean(y) + qnorm(abs(.alpha)/2) * sd(y)}
#lci <- function(y,.alpha){mean(y) - qnorm(abs(.alpha)/2) * sd(y)}
#ggplot(data, aes(x=x,y=y)) +
#	stat_summary(fun.y=mean, geom='line', colour='blue') +
#	stat_summary(fun.y=mean, geom='ribbon', fun.ymax=uci, fun.ymin=lci, .alpha=0.05, alpha=0.5)

#ggplot(data, aes(x=x,y=y)) + 
#	stat_summary(fun.y = 'mean', colour = 'blue', geom = 'line') +
#	stat_summary(fun.data = 'mean_sdl', geom = 'ribbon', alpha = 0.2)
#----------------------------------------------------------
#http://stackoverflow.com/questions/12033319/plot-mean-and-sd-of-dataset-per-x-value-using-ggplot2
a <- data.frame(x=rep(c(1,2,3,5,7,10,15,20), 5),
                y=rnorm(40, sd=2) + rep(c(4,3.5,3,2.5,2,1.5,1,0.5), 5))
stat_sum_df <- function(fun, geom="crossbar", ...) { 
 stat_summary(fun.data=fun, colour="blue", geom=geom, width=0.2, ...) 
} 
q=qplot(x, y, data=a)
q+ stat_sum_df("mean_cl_normal", geom = "smooth") 
#----------------------------------------------------------
message("Press Return To Continue")
invisible(readLines("stdin", n=1))
