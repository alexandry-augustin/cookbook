#!/bin/bash
#----------------------------------------------------------
if [ "$#" -ne 1 ]; then
    echo "usage: bash export.sh filename"
    exit 1
fi
#----------------------------------------------------------
FILENAME=$1
#OUTPATH=html
OUTPATH=.

source ~/.venv/global/bin/activate

# find .. -iname "*.ipynb" -exec 
jupyter nbconvert --to html --output-dir $OUTPATH $FILENAME
