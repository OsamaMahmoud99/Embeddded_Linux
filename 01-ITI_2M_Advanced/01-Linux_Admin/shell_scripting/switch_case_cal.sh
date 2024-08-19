#!/bin/bash
read -p "Enter First Number: " f_num
read -p "Enter Second Number: " s_num
read -p "Enter Operation(+,-,x,/): " op
case $op in
+)
echo "$f_num + $s_num = $[$f_num+$s_num]";;
-)
echo "$f_num $s_num = $[$f_num-$s_num]";;
x)
echo "$f_num x $s_num = $[$f_num*$s_num]";;
/)
echo "$f_num / $s_num = $[$f_num/$s_num]";;
*)
echo "invalid option"
esac