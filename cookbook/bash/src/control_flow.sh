#!/bin/bash
#----------------------------------------------------------
main()
{
	for ((  i = 0 ;  i <= 5;  i++  )); do echo $i; done
	#for ((i=1; i<=10; i++)); do echo $i; done
	#--------------------------------------------------
	for ((  i = 0 ;  i <= 5;  i++  ))
	do
		echo $i
	done
	#--------------------------------------------------
	for ((  i = 0 ;  i <= 5;  i++  ))
	do
		if [ -f "IMG_$i.CR2" ]
		then
			mv "IMG_$i.CR2" my_dir;
		fi
	done
	#--------------------------------------------------
#	PS3=">>> "
#	select fruit in apple banana kiwi stop
#	do
#		echo ""
#	done
	#--------------------------------------------------
#	select FILENAME in *;
#	do
#	     echo "You picked $FILENAME"
#	done
}
#----------------------------------------------------------
main "$@"
