#!/bin/bash

FRUIT=$1

case "$FRUIT" in
   "apple") echo "apple value" 
   ;;
   "banana") echo "banana value" 
   ;;
   "kiwi") echo "kiwi value" 
   ;;
   *)        echo "default value" 
   ;;
esac