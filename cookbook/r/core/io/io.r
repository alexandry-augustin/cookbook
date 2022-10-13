for (i in 1:10)
{
  print(i)
  flush.console()
}


x <- c(1:5)
cat(sprintf("Number: %d\n", x))
cat(sprintf("Number: [%s]\n", paste(x, collapse=" ")))
