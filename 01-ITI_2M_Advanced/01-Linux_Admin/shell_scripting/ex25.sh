#!/bin/bash
total=0
number=0
while [ $number -lt 10 ]
do
        read -p "please enter a number :" number
         if [ $number  -eq 3 ]
         then
                 continue
            fi
        echo will sleep
        sleep 2	
done
         echo $total
