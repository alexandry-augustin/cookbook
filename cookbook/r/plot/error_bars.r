#http://stackoverflow.com/questions/14069629/plotting-confidence-intervals
 set.seed(1234)
 df <- data.frame(x =1:10,
                 F =runif(10,1,2),
                 L =runif(10,0,1),
                 U =runif(10,2,3))

X11()

plot(df$x, df$F, ylim = c(0,4), type = "l")
#make polygon where coordinates start with lower limit and 
# then upper limit in reverse order
polygon(c(df$x,rev(df$x))
	, c(df$L,rev(df$U))
	, col = "grey75"
	, border = FALSE
	)
lines(df$x, df$F, lwd = 2)
#add red lines on borders of polygon
lines(df$x, df$U, col="red",lty=2)
lines(df$x, df$L, col="red",lty=2)

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
