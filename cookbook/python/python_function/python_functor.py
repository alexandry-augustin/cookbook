class base_00(object):
	def __init__(self, n):
		self.n = n
	def __call__(self, x):
		self.n += x
		return self.n

if __name__=='__main__':
	b=base_00(0)
	assert(b.n==0)
	b(1)
	assert(b.n==1)
