class base():
	def __init__(self, n):
		self.n = n
	def __enter__(self):
		print("__enter__ %s"%self.n)
		return self
	def __exit__(self, type, value, traceback):
		print("__exit__ %s"%self.n)

if __name__=="__main__":
	with base(0) as b:
		b.n=1
