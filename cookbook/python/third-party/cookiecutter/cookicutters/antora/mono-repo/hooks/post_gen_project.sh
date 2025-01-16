#!/bin/bash

git init
git config user.name {{cookiecutter.git_username}}
git config user.email {{cookiecutter.git_email}}
git init && git commit --allow-empty -m "Initial commit"