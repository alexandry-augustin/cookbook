import time
#----------------------------------------------------------
if __name__=="__main__":
	start_time=time.time()
	time.sleep(3)
	duration=time.time()-start_time #float

	m, s=divmod(duration, 60)
	h, m=divmod(m, 60)
	print "duration %d:%02d:%02d" % (h, m, s)
