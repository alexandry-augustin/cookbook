#!/bin/sh
#----------------------------------------------------------
main()
{
#choose a limit string sufficiently unusual that it will not occur anywhere in the command list
python <<LimitString
import math
l=range(10)
print(l)
LimitString
}
#----------------------------------------------------------
main "$@"
