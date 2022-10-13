# python -m pdb filename.py
#----------------------------------------------------------
import pdb
#----------------------------------------------------------
# n: next
# enter: repeat last cmd
# p: print
# q: quit
# c: continue
# l: list
# s: step into
# r: return
# w: where
# clear:
#----------------------------------------------------------
if __name__=='__main__':
	a = "aaa"
	pdb.set_trace()
	b = "bbb"
	c = "ccc"
	final = a + b + c
	print final
