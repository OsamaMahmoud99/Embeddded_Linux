#!/bin/bash
a=10
b=20
if [ "$(whoami)" != "root" ] ; then
  echo "Error: You must be root to run this command."
  exit 1
fi

if [ $a == $b ]
then
     echo "a is equal to b"
elif [ $a -gt $b ]
then
   echo "a is greater than b"
elif [ $a -lt $b ]
then
   echo "a is less than b"
else
   echo "None of the condition met"
fi