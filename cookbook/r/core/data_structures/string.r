str <- "abc"
str <- paste(str, "123", sep="_") #default sep=" "

s <- "abc"
stopifnot(typeof(s)=="character")
s <- character(3)
s <- paste("abc", "123", sep="")
s <- sprintf("abc_%i", 123)
s <- sprintf("abc_%s", "123")
s <- cat("abc", 123)
