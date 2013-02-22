Instructions:

The make file will make executables for either a dynamic test or a static test, or both!
You need to cd into the appropriate directory (.../BoundedQueue) on the command line, and then:


Use "make dynamicTest" to make the dynamic test.
Run the dynamic test with "./dynamicTest"
...
What is the dynamic test?  Basically, a command-line program to try out any sort of queue you want.  It allows you to modify the bounded queue on the fly, letting you create any queue of any size and then add or remove elements as you wish.  Check it out for details on commands.

Use "make staticTest" to make the static test.
Run the static test with "./staticTest"
...
What is the static test?  It runs a set of instructions on a fixed-size bounded queue, printing the expected and actual results to standard output.

Use "make" to make both executables

Use "make clean" to clear .o files and executables