#!/bin/bash
echo Bash version  ${BASH_VERSION} 
for i in 1 2 3 4 5
do
  echo "Looping ... number $i"
done


for i in {1..5}
do
   echo Welcome $i times
done

for i in {0..10..2}
  do 
     echo "Welcome $i times"
 done
 
for i in *
do
         echo $i
done

#this way is used to take output of a command and do operations on it 
for i in $(ls)
do
         echo $i
done