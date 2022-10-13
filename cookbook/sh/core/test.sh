#!/bin/sh
#----------------------------------------------------------
# comparisons:
# !		logical not
# -eq (or =)	equal to			==
# -ne (or !=)	not equal to			!=
# -lt		less than			<
# -le		less than or equal to		<=
# -gt		greater than			>
# -ge		greater than or equal to	>=
#----------------------------------------------------------
# file operations:
# -eq
# -d	directory exist
# -e	file/dir exist
# -f	file exist

# -r	file/dir is readable
# -s	file/dir size > 0
# -w	file/dir is writable
# -x	file/dir is executable
#----------------------------------------------------------
# -o	or
# -a	and
#----------------------------------------------------------
# -n	the length of string is >0
# -z	the length of string is 0
#----------------------------------------------------------
main()
{
	IS_VALID=false
#	IS_VALID=test "a" = "b"
	if $IS_VALID; then
		echo "true"
	else
		echo "false"
	fi
	#--------------------------------------------------
	test "a" = "b" #return true if a==b (same as [  ])
	#--------------------------------------------------
	if [ "a" = "b" ]
	# or
	#if test "a" = "b"
	then
		echo "equal"
	fi
	#--------------------------------------------------
	VAR_00=''
	if [ -n "$VAR_00" ]; then
		echo '>0'
	fi
	if [ -z "$VAR_00" ]; then
		echo 'empty'
	fi
	VAR_00='abc'
	if [ -z "$VAR_00" ]; then
		echo 'empty'
	fi
	if [ -n "$VAR_00" ]; then
		echo 'length >0'
	fi
	VAR_00='abc 123'
	if [ -z "$VAR_00" ]; then
		echo 'empty'
	fi
	if [ -n "$VAR_00" ]; then
		echo 'length >0'
	fi
	#--------------------------------------------------
	VAR_00='unknown'
	if [ ! -f "$VAR_00" ]; then
		echo "file \"$VAR_00\" does not exist"
	fi
	#--------------------------------------------------
	DIRECTORY=./_
	if [ -d $DIRECTORY ]; then
#		if [ "$(ls -A $DIRECTORY)" ]; then #check if dir empty (directory must exist)
#			echo "$DIRECTORY is not empty"
#		else
#			echo "$DIRECTORY is empty"
#		fi

		if [ ! "$(ls -A $DIRECTORY)" ]; then
			echo "$DIRECTORY is empty"
		else
			echo "$DIRECTORY is not empty"
		fi
	else
		echo "$DIRECTORY does not exist"
	fi
	#--------------------------------------------------
	LINK=./link
	if [ -L $LINK ]; then
		echo "link "$LINK" exist and is a symlink"
	fi

	if [ -h $LINK ]; then
		echo "symlink "$LINK" exist and (linked file may not exist)"
	fi
			
}
#----------------------------------------------------------
main "$@"
