#!/bin/sh

/usr/local/bin/invalidcommand
if [ $? -ne "0" ]; then
  echo "Sorry, we had a problem there!"
fi

<<comment 
Another special variable is $?. This contains the exit value of the last run command.
will attempt to run /usr/local/bin/my-command which should exit with a value of zero if all went well, or a nonzero value on failure. We can then handle this by checking the value of $? after calling the command. This helps make scripts robust and more intelligent.
comment 


echo "PID OF script session: $$" #The $$ variable is the PID (Process IDentifier) of the currently running shell
 
