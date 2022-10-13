# deprecated since version 2.7
# replaced by argparse
from optparse import OptionParser

if __name__=='__main__':
	parser=OptionParser(usage="usage: %prog [otions]")
	parser.add_option("-f", "--file", dest="filename",
        help="write report to FILE", metavar="FILE")
	parser.add_option("-q", "--quiet",
		action="store_false", dest="verbose", default=True,
                help="don't print status messages to stdout")

	(options, args) = parser.parse_args()
