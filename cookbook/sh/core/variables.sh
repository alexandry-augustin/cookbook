#!/bin/sh
#----------------------------------------------------------
main()
{
	PATH_00=../
	ls -l $PATH_00
	#--------------------------------------------------
	#arithmetic
	#http://www.bashguru.com/2010/12/math-in-shell-scripts.html
	N=3
	#N="N+$1"
	#N=$(($N + $1))
	N=`expr "$N" + 1`
	echo $N
}
#----------------------------------------------------------
main "$@"
