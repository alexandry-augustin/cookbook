import json
import sys # for exit()
#----------------------------------------------------------
class base_00():
	def __init__(self, n):
		self.__n=n
	def get(self):
		return self.__n
	def set(self, n):
		self.__n=n
#----------------------------------------------------------
if __name__=='__main__':
	#str='{"one": "1", "two": 2, "three": [1, 2]}'
	#or
	str='{\
		"one": "1",\
		"two": 2,\
		"three": [1, 2]\
	}'

	try:
		json_00=json.loads(str)
	except ValueError as e:
		print e
		sys.exit(1)

	assert json_00['one']=="1"
	assert json_00['two']==2

	assert json.dumps(json_00)=='{"three": [1, 2], "two": 2, "one": "1"}'
	assert json.dumps(json_00, indent=4, sort_keys=True, separators=(',', ': '))=="""{
    "one": "1",
    "three": [
        1,
        2
    ],
    "two": 2
}"""
	#--------------------------------------------------------
	b_00=base_00(5)
	#json_01=json.dumps(b_00)
	#.read()
