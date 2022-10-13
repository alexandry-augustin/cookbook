#http://www.statmethods.net/advgraphs/parameters.html
#type
#        "p" for points (default)
#        "l" for lines
#        "b" for both
#        "c" for the lines part alone of "b"
#        "o" for both ‘overplotted’
#        "h" for ‘histogram’ like (or ‘high-density’) vertical lines
#        "s" for stair steps
#        "S" for other steps
#        "n" for no plotting
#http://www.cookbook-r.com/Graphs/Output_to_a_file

x <- seq(-20, 20, by=.1)
y <- dnorm(x)

#dev.new()
X11()
#pdf("out.pdf")
#svg("plots.svg")
#png("plot.png", width=800, height=600, res=120)
#tiff("plot.tiff")
plot(x,y, type="l", col="red", r=T
		,xlab="", ylab="", main=""
		) #r: draw axis?
#par(mar=c(5,3,2,2)+0.1) #remove space reserved for labels
#dev.off()

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
