#!/bin/sh
#----------------------------------------------------------
ls_00()
{
	PATH_00=..
	for path in * ./* $PATH_00/* *.tar.bz2 #'path' is a files OR a folder
	do
		echo "$path" #full relative path: file ./file ../../path
#		if [ "$path" = "filename.tar.bz2" ]
#		then
#			echo $file
#		fi
		echo $(basename $path) #strip path when possible
	done
}
#----------------------------------------------------------
ls_01()
{
	FOLDERS=`ls -l | grep '^d' | awk '{print $9}'`
	for item in $FOLDERS
	do
		echo "$item"
	done
}
#----------------------------------------------------------
touch_multi()
{
	for i in $(seq 1 5); do touch file_$i; done
}
#----------------------------------------------------------
main()
{
	ls_00
}
#----------------------------------------------------------
main "$@"
