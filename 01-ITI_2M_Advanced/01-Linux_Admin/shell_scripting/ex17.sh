#!/bin/bash 
#String Operators | Shell Script 
str1="Embedded_linux"; 
str2="embedded"; 
if [ $str1 = $str2 ] 
then 
    echo "Both string are same"; 
else
    echo "Both string are not same"; 
fi

if [ $str1 != $str2 ] 
then 
    echo "Both string are not same"; 
else
    echo "Both string are same"; 
fi

if [ $str1 \< $str2 ] 
then 
    echo "$str1 is less then $str2"; 
else
    echo "$str1 is not less then $str2"; 
fi

if [ $str1 \> $str2 ] 
then 
    echo "$str1 is greater then $str2"; 
else
    echo "$str1 is less then $str2"; 
fi

if [ -n $str ] 
then 
    echo "String is not empty"; 
else
    echo "String is empty"; 
fi

if [ -z $str ] 
then 
    echo "String is empty"; 
else
    echo "String is not empty"; 
fi