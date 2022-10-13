class base(object):
	def __init__(self, n):
		self.n=n
	def __add__(self, other):
		"""
			reverse add:
			base+5
			base+base
		"""
		return self.n+other
	def __radd__(self, other):
		"""
			reverse add:
			5+base
		"""
		return self.n+other
	def __lt__(self, other):
	    return self.n < other
	def __le__(self, other):
	    if isinstance(other, base):
		    return self.n <= other.n
	    elif isinstance(other, (int, float)):
		    return self.n <= other
	    else:
		    return NotImplemented
	def __eq__(self, other):
	    return self.n == other
	def __ne__(self, other):
	    return self.n != other
	def __gt__(self, other):
	    return self.n > other
	def __ge__(self, other):
		if isinstance(other, base):
			return self.n >= other.n
		elif isinstance(other, (int, float)):
			return self.n >= other
		else:
			return NotImplemented
	def __int__(self):
		"""
			cast into int
		"""
		return self.n
	def __iadd__(self):
		"""
			+=
		"""
		pass
	def __isub__(self):
		"""
			-=
		"""
		pass

if __name__=="__main__":
	b=base(5)
	assert(5+b==10)
	assert(b+5==10)
	assert(b<=5)
	assert(b<6)
	assert(b>4)
	assert(b>=5)
