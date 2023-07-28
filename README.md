/*****************************************************************************
TITLE: Claims																																
AUTHOR:   2101CS69
Declaration of Authorship
This text file, claims.txt, is part of the mini project of CS209 at the 
Department of Computer Science and Engg, IIT Patna. 
*****************************************************************************/

Files:
==========
*All the files I submitted, asm.c and emu.c and claims.txt, have my name and student id at the start, along with a declaration of authorship.

The evidence for Assembler including the output files from the 6 test examples has also been uploaded. They are test1(3 output files), test2(3 output files),test3(3 output files) ,test4(3 output files), Bubble_sort(3 output files), Perimeter of rectangle(3 output files). All the test files have been tested and work properly. As for the evidence for the emulator is uploaded
with bubble sort output file.

*Both of my cpp programs did not show any errors and warnings when i compiled it with
g++ -std=c89 -pedantic and g++ -std=c89 -pedantic -W -Wall -Wpointer-arith -Wwrite-strings -Wstrict-prototypes standard  or equilvalent ....or gcc ... or g++

*Two programs are compatible with g++ asm.c -o asm and g++ emu.c -o emu.


=============================
Program format and structure:
=============================
1. The assembler:

     with two data structures to store respectively labels and mnemonic table with expected operands.
     uses a single routine for both passes.
     detects label errs (a total of 12 error types with 2 warning types are available).
     the more detailed level of error checks
     consistent and sensible formatting with sensible program structure. 
     sensible variable, function & type names with explanatory comments.
		 advanced listing file.
		 assembles test programs.
	   implements and demonstrates the instruction SET.
The assembler creates one extra output file which is hex code dump, which then after is used to convert it to binary machine code.

2. The emulator ( if you are submitting) :

- it asks you for a trace and other 3 options which you can see when running. 
- after running it will give you the option to show the dump. write -dump
then add the address and number of dumps you want to see.
// Note:- you can try for 1440 lines in the bubble sort
-


=============================
Testing:
=============================

1. The assembler:

I have tested  6/the 6 examples shown below. The errors only occurred in the file test2.asm and 
the program immediately stopped on the second pass. 

The others were tested without any errors detected and produced three output files, a listing file, 
error log file and a machine-readable object file, for each example. 
 

1)
#Input: asm test1.asm
#Output: 
a. test1.list 
b. test1.log (without any error messages)
c. test1.o

2)
#Input:asm test2.asm
#Output: 
a. test2.l 
b. test2.log (with error messages shown below but also in the log file)
c. test2.o

Similarly, you can check for other cases.



2. The emulator:

I have tested three examples(test_1,test_2,bubble_sort)
 shown for which I have uploaded one image in the bubble sort, showing how it works.
 The errors only occurred in the file test3.o and 
the program immediately stopped with an error message on the screen. 

The others were tested without any errors detected and produced execution data both on the screen and 
output text file for each example according to the usage instruction. 

After running the bin file given, the trace data are the same as 
the implemented result from my own program.

It will show you options to trace/ exit/ all / dump, when you select dump, you can select the address for which to dump and then select
the address of the dump which you want, then select the number of dumps. It will show you all the dumps inside it. 
 # Assembler and Emulator in C++
The aim of this miniproject is to write a two pass assembler for an extended SIMPLE instruction set.
Read assembly language from a text file, assigning label values and instruction opcodes. The format of the assembly language is described. 
Diagnose common assembly errors such as unknown instruction, no such label, duplicate label. 
Shows bytes produced for each instruction, and that instruction's mnemonic.
ISO C89 working!


The emulator part
Loads object file. 
Produces memory dump. 
Executes test program


