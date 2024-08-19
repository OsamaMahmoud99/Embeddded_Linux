#! /bin/bash 
#array in shell
# To declare static Array 
arr=(hi linux 1 2 how_are_you ALI) 

# To print all elements of array 
echo ${arr[@]}	 
echo ${arr[*]}	 
echo ${arr[@]:0}	 
echo ${arr[*]:0}	 

echo ${arr[0]}
echo ${arr[5]}
echo ${arr[6]}
echo ${arr[@]:1:4}  #print in range