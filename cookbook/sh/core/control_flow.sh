#!/bin/sh
#----------------------------------------------------------
#set -x
#trap read debug
#----------------------------------------------------------
if_else()
{
	FILENAME=file
	if [ -f $FILENAME ]; then echo "exist"; else echo "doesn't exist"; fi
	#or
	#if [ -f $FILENAME ];then echo "file";echo "exist";else echo "doesn't"; echo "exist";fi
	#--------------------------------------------------
	if [ "a" = "b" ]; then
		echo "equal"
	fi
	#--------------------------------------------------
	if [ "a" = "b" ] #all spaces here are important
	then
		echo "equal"
	else
		echo "not equal"
	fi
	#--------------------------------------------------
	VAR=""
	if [ "$VAR" ]; then
		echo "exist and is not empty"
	else
		echo "empty or haven't been declared"
	fi
}
#----------------------------------------------------------
for_()
{
	for i in $(seq 1 5); do echo $i; done
	#--------------------------------------------------
#	for i in 1 2 3 4 5 
	for i in $(seq 1 5) #$(seq start step end)
	do
		echo $i
	done
	#--------------------------------------------------
	#floats
	num=$(awk 'BEGIN{for(i=1;i<=10;i+=0.1)print i}')
	for n in $num
	do
		echo $n
	done
}
#----------------------------------------------------------
while_()
{
	#--------------------------------------------------
#	while true; do
#		sleep 1
#	done
	#--------------------------------------------------
	while [ "a" = "b" ]
	do
		echo "not equal"
	done
	#--------------------------------------------------
#	while [ false ]; do
#		echo "not equal"
#	done
}
#----------------------------------------------------------
main()
{
	#break
	#continue

	if_else
	for_
	while_
	#--------------------------------------------------
	until [ "a" = "a" ]
	do
		echo "not equal"
	done
	#--------------------------------------------------
	c="V"
	case "$c" in 
	a|A)
		echo "a or A"
		;;
	B)
		echo "B"
		;;
	?)
		echo "any single character"
		;;
	*)
		echo "default"
		;;
	esac
}
#----------------------------------------------------------
main "$@"
