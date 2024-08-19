#!/bin/bash
while [ 1 ]
do
        read -p  "please enter a number :" number
         if [ $number -eq 1 ]
         then
                 break
         fi
		 echo "enter 1 to exit"
done
         echo $total
