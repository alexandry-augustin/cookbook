#!/bin/sh
#----------------------------------------------------------
main()
{
	STR_00='abcde'
	#--------------------------------------------------
	if [ $STR_00 != 'abcde' ]
	then
		echo 'error'
	fi
	#--------------------------------------------------
	echo ${#STR_00} #length of STR_00
	#--------------------------------------------------
}
#----------------------------------------------------------
main "$@"
