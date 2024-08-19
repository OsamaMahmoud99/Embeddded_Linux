#!/bin/bash

echo -n "What is your name [ `whoami` ] " # -n is used to not add line break in echo
read myname
if [ -z "$myname" ]; then
  myname=`whoami`
fi
echo "Your name is : $myname"
