#!/bin/bash 
#Logical Operators : They are also known as boolean operators. These are used to perform logical operations. They are of 3 types:
#reading data from the user 
read -p 'Enter a : ' a 
read -p 'Enter b : ' b 

if [ $a == "true" ]  &&  [ $b == "true" ]  # [[ $a == "true"  &&  $b == "true" ]] 
then
	echo Both are true. 
else
	echo Both are not true. 
fi

if  [ $a == "true" ]  ||  [ $b == "true" ] 
then
	echo Atleast one of them is true. 
else
	echo None of them is true. 
fi

if  ! [  $a == "true" ] 
then
	echo "a" was intially false. 
else
	echo "a" was intially true. 
fi
