#!/bin/sh #shebang line
#----------------------------------------------------------
#chmod u+x file_name.sh => ./file_name.sh
#----------------------------------------------------------
# sh -x file_name
#----------------------------------------------------------
#line break (no more characteres allowed after \)
echo "tes\
t" #"test"
#----------------------------------------------------------
# $*			entire argument string
# $@			complete command line args (without script name)
# $0			script filename
# $1, $2, $3 ...	command line arguments
# $#			number of arguments
# $?			return code from the last command issued
echo "$@"
if [ $# = 2 ]; then
	echo "args=2: $1 $2"
else
	if [ $# = 1 ]; then
		echo "args=1: $1"
	else
		echo "args!=2"
	fi
fi
#----------------------------------------------------------
exit 0
