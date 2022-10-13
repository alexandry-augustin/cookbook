#----------------------------------------------------------
#	writing to file
#----------------------------------------------------------
fileConn<-file("output.txt")
writeLines(c("abc","123"), fileConn)
writeLines("cde", fileConn)
writeLines("456", fileConn)
close(fileConn)
#----------------------------------------------------------
sink("output.txt")
cat("abc\n")
cat("123")
sink()
#----------------------------------------------------------
if(file.exists("output.txt"))
{
	file.remove("output.txt")
}
#----------------------------------------------------------
#file.create(..., showWarnings = TRUE)
#file.rename(from, to)
#file.append(file1, file2)
#file.copy(from, to, overwrite = recursive, recursive = FALSE,
#          copy.mode = TRUE, copy.date = FALSE)
#file.symlink(from, to)
