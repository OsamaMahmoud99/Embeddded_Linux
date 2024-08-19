#!/bin/bash
<<comment
Once the shell script exits, its environment is destroyed. But MYVAR keeps its value of hello within your interactive shell.
In order to receive environment changes back from the script, we must source the script - this effectively runs the script within our own interactive shell, instead of spawning another shell to run it.
We can source a script via the "." (dot) command: 
try those in your shell
$ MYVAR=hello
$ echo $MYVAR
$ . ./myvar2.sh
$ echo $MYVAR
comment

echo "MYVAR is: $MYVAR"
MYVAR="hi there"
echo "MYVAR is: $MYVAR"

