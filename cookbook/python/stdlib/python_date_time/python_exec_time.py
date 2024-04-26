import time

def format_duration(value: float):

	m, s=divmod(duration, 60)
	h, m=divmod(m, 60)
	
	return "%d:%02d:%02d" % (h, m, s)

if __name__=="__main__":

	start_time = time.time()
	n=3
	print(f'waiting {n}s')
	time.sleep(n)
	duration = time.time()-start_time
	assert(type(duration) == float)
	duration = format_duration(duration)
	assert(type(duration) == str)
	
	print(f'duration: {duration}')