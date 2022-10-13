#!/bin/bash
#----------------------------------------------------------
assert()
{
	E_PARAM_ERR=98
	E_ASSERT_FAILED=99

	if [ -z "$2" ]; then
		return $E_PARAM_ERR
	fi

	lineno=$2

	if [ ! $1 ]; then
		echo "Assertion failed:  \"$1\""
		echo "File \"$0\", line $lineno" #give name of file and line number
		exit $E_ASSERT_FAILED
#	else
#   		return #continue executing the script
	fi  
}
