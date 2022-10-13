#dice example
kappa <- c(1,1,1,1,1,1)
nb_throws <- 2
as.vector(rmultinom(1, nb_throws, kappa))
