i: data 0
j: data 0
a: data 2
b: data 6
res: data 0

loop:
ldc i
ldnl 0
ldc b
ldnl 0
sub
brz done
ldc a
ldnl 0
ldc res
ldnl 0
add
ldc res
stnl 0
ldc i
ldnl 0
ldc 1
add
ldc i
stnl 0
br loop
done:
HALT

; i and j are variables. i is being used as the loop control variable while j has not been used for anything.
; a and b are the 2 numbers to be multiplied.
; res is the memory location where the product of a and b shall be stored post execution.
; to assemble this freshly (assuming that asm.cpp has already been compiled), run the following command: ./asm multiply.asm
; the above shall generate the files object_file.o, listing_file.l and errors.log
; to execute it freshly with the object code obtained upon assembling using the emulator(assuming emu.cpp has already been compiled), run the following command: ./emu object_file.o
; the above shall generate the files memory_dump.txt and trace.txt
