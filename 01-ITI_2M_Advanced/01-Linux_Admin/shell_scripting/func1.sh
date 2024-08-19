#!/bin/bash

myfunc()
{
  echo "\$1 is $1"
  echo "\$2 is $2"

  a="Goodbye "
  c="insidefun"
}

### Main script starts here 

a=Hello
b=World
myfunc $a $b
echo $1 $2
echo "a is $a"
echo "b is $b"
echo $c