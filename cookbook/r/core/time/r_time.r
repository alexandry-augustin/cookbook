ptm <- proc.time()
Sys.sleep(3) #in seconds
proc.time() - ptm
#----------------------------------------------------------
system.time(a <- seq(0, 10, 1)) #wrapper around proc.time() to monitor function call
