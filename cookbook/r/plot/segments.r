#http://stackoverflow.com/questions/15063287/add-error-bars-to-show-standard-deviation-on-a-plot-in-r

x=1:5
y=c(1.1, 1.5, 2.9, 3.8, 5.2)
sd=c(0.1, 0.3, 0.2, 0.2, 0.4)

X11()
plot (x, y, ylim=c(0, 6))

segments(x, y-sd, x, y+sd)
epsilon=0.02
segments(x-epsilon, y-sd, x+epsilon, y-sd)
segments(x-epsilon, y+sd, x+epsilon, y+sd)

#qplot(x,y)+geom_errorbar(aes(x=x, ymin=y-sd, ymax=y+sd), width=0.25)

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
