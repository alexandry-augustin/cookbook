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
echo "* xref:index.adoc[]" > $COMPONENT_NAME/modules/ROOT/nav.adoc
echo "= Home" > $COMPONENT_NAME/modules/ROOT/pages/index.adoc

echo "name: $COMPONENT_NAME" >> $COMPONENT_NAME/antora.yml
echo "version: ~"  >> $COMPONENT_NAME/antora.yml
echo "title: $COMPONENT_NAME"  >> $COMPONENT_NAME/antora.yml
echo "nav:"  >> $COMPONENT_NAME/antora.yml
echo "- modules/ROOT/nav.adoc"  >> $COMPONENT_NAME/antora.yml

# Git

mkdir git/$COMPONENT_NAME
cd git/$COMPONENT_NAME

git init
git config user.name alex
git config user.email alexandry.augustin@gmail.com
git init && git commit --allow-empty -m "Initial commit"

ln -s ../../$COMPONENT_NAME/antora.yml .
ln -s ../../$COMPONENT_NAME/modules/ .

echo "Remember to:"
echo "    * add '$COMPONENT_NAME' to 'sources' in ./site/antora-playbook.yml"
echo "    * edit 'title' in ./$COMPONENT_NAME/antora.yml"
echo "    * run 'git add ./'$COMPONENT_NAME'"
