#!/bin/bash
HOST=$1
USERNAME=$2
shift  # drop the HOST
shift  # drop the USERNAME
PASSWORD=$@  # PASSWORD is whatever remains

echo "Host is $HOST ; Username is $USERNAME ; Password is $PASSWORD"