# High Density Scatterplot with Color Transparency
# pdf("c:/scatterplot.pdf")
x <- rnorm(1000)
y <- rnorm(1000)
plot(x,y)
# plot(x,y, main="PDF Scatterplot Example", col=rgb(0,100,0,50,maxColorValue=255), pch=16)
# dev.off()
