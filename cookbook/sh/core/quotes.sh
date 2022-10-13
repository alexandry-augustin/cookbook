#!/bin/sh
#----------------------------------------------------------
# ' '	any special characters are treated literally
# " "	assign a string that contains special characters the shell should act on
#----------------------------------------------------------
# http://www.gnu.org/software/bash/manual/bashref.html#Quoting
# 3.1.2.2 Single Quotes
# Enclosing characters in single quotes (‘'’) preserves the literal value of each character within the quotes. A single quote may not occur between single quotes, even when preceded by a backslash.
# 
# 3.1.2.3 Double Quotes
# Enclosing characters in double quotes (‘"’) preserves the literal value of all characters within the quotes, with the exception of ‘$’, ‘`’, ‘\’, and, when history expansion is enabled, ‘!’. The characters ‘$’ and ‘`’ retain their special meaning within double quotes (see Shell Expansions). The backslash retains its special meaning only when followed by one of the following characters: ‘$’, ‘`’, ‘"’, ‘\’, or newline. Within double quotes, backslashes that are followed by one of these characters are removed. Backslashes preceding characters without a special meaning are left unmodified. A double quote may be quoted within double quotes by preceding it with a backslash. If enabled, history expansion will be performed unless an ‘!’ appearing in double quotes is escaped using a backslash. The backslash preceding the ‘!’ is not removed.
# The special parameters ‘*’ and ‘@’ have special meaning when in double quotes (see Shell Parameter Expansion).
#----------------------------------------------------------
main()
{
	STR_00='abc'
	STR_01='abc$123\n'
	STR_02='this is a quote: '"'"
	#--------------------------------------------------
	echo $STR_02
	#--------------------------------------------------
}
#----------------------------------------------------------
main "$@"
