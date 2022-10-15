import bases			#include <bases.py>;
from bases import base_00	#include <bases.py>; using base.base1;
from bases import *		#include <bases.py>; using namespace bases;
import somedir.base
import __builtin__
#----------------------------------------------------------
# when a module is imported, all its code is parsed:
#   - a syntax exception is raised if an error is found.
#   - if everything ok, a .pyc file is created.
#----------------------------------------------------------
def other():
	help(bases)
	print(dir(__builtin__))

if __name__=='__main__':
	f_00()
	b_00=bases.base_00(9)
	b_01=somedir.base.base_01(9)
	print(dir(bases))
	#or
	print(bases.__dict__.keys())
