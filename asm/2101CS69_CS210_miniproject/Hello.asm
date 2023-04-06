label1:    ;How much left
data 50
label2:   ; SP ka last saved value
data 0
label3:   ; first element
data 1
label4:   ; second element
data 1 

loop:

ldc 0;
ldc 0;
a2sp

ldc label1    ; A contains address of label 1
ldnl 0        ; A= memory(A+0) = 10
brz exit      ; A =10
ldl 2         ; B=10 A=1
sub           ; A=9
stl 0         ; stores n-1 after every loop

ldc 0
ldc 0

ldc label2    ; Bringing back SP ka value
ldnl 0
a2sp


ldl 2         ; B=A , A=1    SP+2 (2)
adj 1         ; PC=PC+1      SP+=1 (PC=1)
ldl 2         ; B=A (B=1, A = 1)  SP+2 (3)
add
stl 3         ; memory(4)= 2

ldc 0;
ldc 0; A=B=0


;STORING NEW SP
ldc label2    ; A=SP
ldnl 0
ldc 1         ; A=1 B=SP
add
ldc 0
a2sp
stl 1         ; storing new SP
stl 1


ldc 0
ldc 0

brz loop 

exit:
HALT



   