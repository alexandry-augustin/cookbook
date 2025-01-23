#!/bin/bash
#----------------------------------------------------------
if [ "$#" -ne 1 ]; then
    echo "usage: bash create-component.sh COMPONENT_NAME"
    exit 1
fi
#----------------------------------------------------------
COMPONENT_NAME=$1

# Main

mkdir -p $COMPONENT_NAME/modules/ROOT/pages
echo "** xref:index.adoc[]" > $COMPONENT_NAME/modules/ROOT/nav.adoc
echo "= Home" > $COMPONENT_NAME/modules/ROOT/pages/index.adoc

# Git

mkdir git/$COMPONENT_NAME
cd git/$COMPONENT_NAME

git init
git config user.name alex
git config user.email alexandry.augustin@gmail.com
git init && git commit --allow-empty -m "Initial commit"

ln -s ../../$COMPONENT_NAME/antora.yml .
ln -s ../../$COMPONENT_NAME/modules/ .
