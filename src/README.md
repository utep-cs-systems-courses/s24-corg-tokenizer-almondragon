tokenizerProgram
====================
## DESCRIPTION:

The *tokenizerProgram* is a program that is meant to tokenize a string of
words and maintain the history of all strings inputted during the duration of
the program. Its workings are similar to that of the split function seen in
other programming languages such as Java or Python. In this program, the user
will input a string, this string is then tokenized, or rather split by the
spaces. The program will return the split words after the user has pressed
'enter' after the input symbol has been prompted. This string is then
maintained in the history of the program and can be called at any time. The
history will show all strings that have been inputted to the program. In
addition, this program can return the string that was tokenized at a certain
ID in the history. For more information on how to compile and run the program,
refer to the headings below.

## COMPILE & MAKE:

   - 'make all' creates the tokenizerProgram, this must be done before running.
   - 'make run' runs the tokenizerProgram.
   - 'make clean' removes any objects files as well as the program itself

## COMMANDS IN PROGRAM:

   - '>' indicates the program is ready to recieve input. Type in a string of
   100 chars.

You may use all the following commands:

   - 'history' will return the history of the program, all strings that have
   been inputted

   - '!d' d represents a number. when calling '!d', the program returns the d
     input of the program. For example, "hello world" was the first
     input. Typing '!1' will return that string

   - 'e' ends the program. "Program ended" will be printed to indicate such.
