# trailingOnly=TRUE means that only your arguments are returned, check:
args <- commandArgs(trailingOnly=TRUE)

args
#as.Date(args[1])
as.integer(args[1])
