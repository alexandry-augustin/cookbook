#!/usr/bin/Rscript

# Eric Vallabh Minikel
# CureFFI.org
# 2014-01-14
# example of how to use optparse in R scripts
# https://gist.github.com/ericminikel/8428297

# usage: ./exampleRScript1.r -a thisisa -b hiagain
#        ./exampleRScript1.r --avar thisisa --bvar hiagain

suppressPackageStartupMessages(require(optparse)) # don't say "Loading required package: optparse"
# manual: http://cran.r-project.org/web/packages/optparse/optparse.pdf
# vignette: http://www.icesi.edu.co/CRAN/web/packages/optparse/vignettes/optparse.pdf

option_list = list(
  make_option(c("-a", "--avar"), action="store", default=NA, type='character',
              help="just a variable named a"),
  make_option(c("-b", "--bvar"), action="store", default=NA, type='character',
              help="just a variable named b"),
  make_option(c("-v", "--verbose"), action="store_true", default=TRUE,
              help="Should the program print extra stuff out? [default %default]"),
  make_option(c("-q", "--quiet"), action="store_false", dest="verbose",
              help="Make the program not be verbose."),
  make_option(c("-c", "--cvar"), action="store", default="this is c",
              help="a variable named c, with a default [default %default]")  
)
opt = parse_args(OptionParser(option_list=option_list))

if (opt$v) {
    # you can use either the long or short name
    # so opt$a and opt$avar are the same.
    cat("avar:\n")
    cat(opt$avar)
    cat("\n\na:\n")
    cat(opt$a)
    
    # show the user what b and c are
    cat("\n\nb:\n")
    cat(opt$b)
    cat("\n\nc:\n")
    cat(opt$c)
    cat("\n\n")
    
    # show the user the difference between cat, write and print
    cat("cat(opt$c): \n")
    cat(opt$c) # does NOT produce its own \n
    cat("\n\nwrite(opt$c,file=stdout()): \n")
    write(opt$c,file=stdout()) # does produce its own \n
    cat("\n\nprint(opt$c,quote=FALSE): \n")
    print(opt$c,quote=FALSE) # no way to remove [1] from in front of line. does produce its own \n.
    cat("\n\n")
}

# main point of program is here, do this whether or not "verbose" is set
if(!is.na(opt$avar) & !is.na(opt$bvar)) {
    cat("here are strings a and b together at last:\n")
    cat(paste(opt$a,opt$b,sep=''))
    cat("\n\n")
} else {
    cat("you didn't specify both variables a and b\n", file=stderr()) # print error messages to stderr
}


