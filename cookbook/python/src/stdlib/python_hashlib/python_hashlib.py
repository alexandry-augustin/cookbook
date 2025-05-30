"""
	http://pythoncentral.io/hashing-strings-with-python/
"""
import hashlib

if __name__=="__main__":
	hash_object = hashlib.sha1(b'Hello World')
	hex_dig = hash_object.hexdigest()
	print(hex_dig)

	print(hashlib.sha1(b'Hello World').hexdigest())
