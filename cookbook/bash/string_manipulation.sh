#!/bin/bash
#----------------------------------------------------------
#http://www.softpanorama.org/Scripting/Shellorama/Reference/string_operations_in_shell.shtml
#----------------------------------------------------------
main()
{
	STR_00='abcde'
	#--------------------------------------------------
	#substring: ${var:position:len} (0-based indexing)
	echo ${STR_00:2} #'cde'
	echo ${STR_00:0:4} #'abcd'
}
#----------------------------------------------------------
main "$@"
