#!/bin/bash
read -p "What is your name?: " USER_NAME
echo "Hello $USER_NAME"
echo "I will create you a file called ${USER_NAME}_file"
touch "${USER_NAME}_file"
readonly USER_NAME
USER_NAME=new_user_name
echo $USER_NAME

#Do lab1 in slides
