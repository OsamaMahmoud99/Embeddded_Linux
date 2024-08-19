#!/bin/bash
user_name="Muhu"
password="1234"
read -p "User Name: " login_name
read -p "Password: " login_pass
echo ""

if [ $login_name = $user_name ] 
then 
    if [ $login_pass = $password ] 
	then 
		echo "Now you are logged in....."
	else
		echo "Error, wrong password, try again"
	fi
else
    echo "Error, user name doesn't exist"
fi