# user defined mod() function
# http://stackoverflow.com/questions/2547402/standard-library-function-in-r-for-finding-the-mode
#----------------------------------------------------------
Mode <- function(x)
{
	ux <- unique(x)
	tab <- tabulate(match(x, ux))
	ux[tab == max(tab)]
}
#----------------------------------------------------------
#x <- sample(1:10, 10, replace=T)
x <- c(9,9,9,2,2,4,4,4)
x
Mode(x)[1]
