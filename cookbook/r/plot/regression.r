require(stats)

# par(mgp=c(2,1,0), mar=c(3,3,1,1))

reg <- lm(dist~speed, data=cars)
coeff = coefficients(reg)

# eq_label = paste0("y = ", round(coeff[2],1), "*x ", round(coeff[1],1))

plot(cars) #, main=eq_label)
abline(reg, col="blue")
