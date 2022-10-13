#!/bin/sh #shebang line
#----------------------------------------------------------
# simular to .
# execute in the same process as the scrip
# does not return control to the original script (can only be used as the last command)
# run faster
#----------------------------------------------------------
main()
{
	start_time=`date +%s`
	sleep 3
	end_time=`date +%s`
	echo execution time was `expr $end_time - $start_time`s
	#--------------------------------------------------
	date
	exec date
	echo "never reached"
	#--------------------------------------------------
}
#----------------------------------------------------------
main "$@"
