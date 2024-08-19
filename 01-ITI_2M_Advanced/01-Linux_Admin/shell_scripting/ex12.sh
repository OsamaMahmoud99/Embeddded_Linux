#!/bin/bash
x=10.2
y=7
echo `echo $x+$y |bc`
echo `echo $x-$y|bc`
echo `echo $x\*$y|bc`
echo `echo $x/$y|bc`
echo `echo $x%$y|bc`
echo `echo $x^$y|bc`

#for more about bc >> https://www.geeksforgeeks.org/bc-command-linux-examples/
