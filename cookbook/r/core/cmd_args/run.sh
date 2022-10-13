#!/bin/sh
Rscript cmd_args.r 1 b "1 2 3"

Rscript optparse.r -a ooo
#Rscript optparse.r -a thisisa -b hiagain
#Rscript --avar thisisa --bvar hiagain
