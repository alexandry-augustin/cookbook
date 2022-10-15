import json
import sys

if __name__=='__main__':

  if len(sys.argv) == 1:
    print "Usage: %s filename" % sys.argv[0]
    sys.exit(1)

  filename=sys.argv[1]

  try:
    file=open(filename, 'r')  
    data=file.read()
    file.close()
  except:
    print "Error processing file %s" % filename
    sys.exit(1)

  try:
    json.loads(data)
  except ValueError as e:
    print "Error in %s: %s" % (filename, e)
    lbound=str(e).find("(char ")
    ubound=str(e).find(")")
    sep=lbound+str(e)[lbound:ubound].find(" - ")
    if sep == lbound-1:
      pos=int(str(e)[lbound+6:ubound])
      print data[0 if pos-20 < 0 else pos-20:pos+20]
    else:
      pos1=int(str(e)[lbound+6:sep])
      pos2=int(str(e)[sep+3:ubound])
      print data[0 if pos1-20 < 0 else pos1-20:pos2+20]
    sys.exit(1)
  
  print "%s contains no errors" % filename
