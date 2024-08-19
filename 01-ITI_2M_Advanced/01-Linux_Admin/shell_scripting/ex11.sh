#!/bin/bash
x=10
y=10
echo $(($x + $y))
echo $(($x -$y))
echo $(($x*$y))
echo $(($x/$y))
echo $(($x%$y))
echo $(($x ** $y))

m=10
n=20
echo `expr $m + $n`
echo 'expr $m + $n'
echo "`expr $m + $n`"
echo `expr $m - $n`
echo `expr $m \* $n` #escape operator used since * is used for all files in the current directory
echo `expr $m / $n`
echo `expr $m % $n`

