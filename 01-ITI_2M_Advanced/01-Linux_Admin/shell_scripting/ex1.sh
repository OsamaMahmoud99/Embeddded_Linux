#!/bin/bash
#Example for echo and printf
x=1 
y="ahmed"
#try with 
#x=1
#y="ahmed"
echo  $x $y
echo "values $x $y"
printf "%s %d\n" $y $x

<<comment
Note that there must be no spaces around the "=" sign: VAR=value works; VAR = value doesn't work. In the first case, the shell sees the "=" symbol and treats the command as a variable assignment. In the second case, the shell assumes that VAR must be the name of a command and tries to execute it.
comment
