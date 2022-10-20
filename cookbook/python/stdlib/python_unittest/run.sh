#!/bin/sh

echo $#
if [ $# != 1 ]; then
	exit 1
fi

FLAGS='-v'

python $1 $FLAGS
