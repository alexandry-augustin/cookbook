#!/bin/bash
#----------------------------------------------------------
# declare OPTION(s) VARIABLE=value
#
# -a	Variable is an array.
# -f	Use function names only.
# -i	The variable is to be treated as an integer; arithmetic evaluation is performed when the variable is assigned a value (see Section 3.4.6).
# -p	Display the attributes and values of each variable. When -p is used, additional options are ignored.
# -r	Make variables read-only. These variables cannot then be assigned values by subsequent assignment statements, nor can they be unset.
# -t	Give each variable the trace attribute.
# -x	Mark each variable for export to subsequent commands via the environment.
#
# no option to declare string values (because by default, a variable can hold any type of data)
#----------------------------------------------------------
# readonly OPTION VARIABLE(s)
#----------------------------------------------------------
strings()
{
	#error if any spaces before or after the equal sign

	var='abc'	
	echo $var	
	echo "${var}_${var}"

	#concatenation
	a="one"
	b="two"
	c=$a$b
	d=$c"three"

	echo $d
}
#----------------------------------------------------------
arrays()
{
	a[0]=5
	echo ${a[0]}
}
#----------------------------------------------------------
main()
{
	strings
	arrays
	declare -i n=5
}
#----------------------------------------------------------
main "$@"
