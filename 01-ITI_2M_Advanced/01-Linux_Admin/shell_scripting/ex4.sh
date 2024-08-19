#!/bin/bash
<<comment
Scope of Variables
Variables in the Bourne shell do not have to be declared, as they do in languages like C. But if you try to read an undeclared variable, the result is the empty string. You get no warnings or errors. This can cause some subtle bugs - if you assign
comment

echo "MYVAR is: $MYVAR"
MYVAR="hi there"
echo "MYVAR is: $MYVAR"

# define MYVAR=hello in your shell then ./ex4.sh and guess the outout

<<comment
When you call ex4.sh from your interactive shell, a new shell is spawned to run the script. This is partly because of the #!/bin/sh line at the start of the script, which we discussed earlier.
We need to export the variable for it to be inherited by another program - including a shell script. 
so export MYVAR then ./ex4.sh
comment


