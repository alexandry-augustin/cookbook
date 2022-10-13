x <- 0:9
y <- rnorm(10)
data <- data.frame(x,y)

summary(data)
#stats <- summarySE(data, measurevar="len", groupvars=c("supp","dose"))
