#!/bin/bash

git init
git config user.name {{cookiecutter.git_name}}
git config user.email {{cookiecutter.git_email}}
git init && git commit --allow-empty -m "Initial commit"