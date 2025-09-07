#!/bin/bash
#----------------------------------------------------------
if [ "$#" -ne 2 ]; then
    echo "usage: bash create-component.sh COMPONENT_SLUG COMPONENT_VERBOSE_NAME"
    exit 1
fi
#----------------------------------------------------------
COMPONENT_SLUG=$1
COMPONENT_VERBOSE_NAME=$2

# Main

mkdir -p $COMPONENT_SLUG/modules/ROOT/pages
echo "* xref:index.adoc[]" > $COMPONENT_SLUG/modules/ROOT/nav.adoc
echo "= "$COMPONENT_VERBOSE_NAME > $COMPONENT_SLUG/modules/ROOT/pages/index.adoc

echo "name: $COMPONENT_SLUG" >> $COMPONENT_SLUG/antora.yml
echo "version: ~"  >> $COMPONENT_SLUG/antora.yml
echo "title: $COMPONENT_SLUG"  >> $COMPONENT_SLUG/antora.yml
echo "nav:"  >> $COMPONENT_SLUG/antora.yml
echo "- modules/ROOT/nav.adoc"  >> $COMPONENT_SLUG/antora.yml

# Git

mkdir git/$COMPONENT_SLUG
cd git/$COMPONENT_SLUG

git init
git config user.name alex
git config user.email alexandry.augustin@gmail.com
git init && git commit --allow-empty -m "Initial commit"

ln -s ../../$COMPONENT_SLUG/antora.yml .
ln -s ../../$COMPONENT_SLUG/modules/ .

echo "Remember to:"
echo "    * add '$COMPONENT_SLUG' to 'sources' in ./site/antora-playbook.yml"
echo "    * edit 'title' in ./$COMPONENT_SLUG/antora.yml"
echo "    * run 'git add ./'$COMPONENT_SLUG'"
