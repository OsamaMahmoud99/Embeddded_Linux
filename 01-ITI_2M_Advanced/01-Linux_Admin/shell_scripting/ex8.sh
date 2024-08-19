#!/bin/bash
# note that $# and $1 .. $9 are set automatically by the shell.
echo "I was called with $# parameters"
echo "My name is $0"
echo "My first parameter is $1"
echo "My second parameter is $2"
echo "All parameters are $@" #$@ expands to multiple arguments
echo "All parameters are $*" #$* expands to a single argument with all the elements delimited by spaces

echo "With *:"
for arg in "$*"; do echo "<$arg>"; done
echo
echo "With @:"
for arg in "$@"; do echo "<$arg>"; done

#run ./ex8.sh  1 2 3 4
#run ./ex8.sh hello world earth
