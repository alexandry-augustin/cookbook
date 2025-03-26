#!/bin/bash

# Site repo

git init
git config user.name {{cookiecutter.git_username}}
git config user.email {{cookiecutter.git_email}}
# git add *

# Component "{{cookiecutter.component_name}}" repo

cd ./git/{{cookiecutter.component_name}}

git init
git config user.name {{cookiecutter.git_username}}
git config user.email {{cookiecutter.git_email}}
git init && git commit --allow-empty -m "Initial commit"

ln -s ../../{{cookiecutter.component_name}}/antora.yml
ln -s ../../{{cookiecutter.component_name}}/modules/