#!/bin/bash

read -s MY_VAR
echo $MY_VAR

read -s -p "value: " MY_VAR_WITH_CUSTOM_PROMPT
echo $MY_VAR_WITH_CUSTOM_PROMPT

read -s MY_PASS
echo $MY_PASS

read -s -p "password: " MY_PASS_WITH_CUSTOM_PROMPT
echo $MY_PASS_WITH_CUSTOM_PROMPT