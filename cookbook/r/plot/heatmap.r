x <- matrix(1:4, 2 ,2)
X11()
heatmap(x
	, main="", xlab="", ylab="",	
	)

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
