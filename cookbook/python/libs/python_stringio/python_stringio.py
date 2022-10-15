import StringIO
#cStringIO — Faster version of StringIO

if __name__=='__main__':

	msg="abc\n123"
	buf = StringIO.StringIO(msg)
	buf.readline()
	buf.readline()
