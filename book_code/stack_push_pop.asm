; Subroutines for carrying out the PUSH and POP functions.
; This program works with a stack consisting of memory locations x3FFF
; (BASE) through x3FFB (MAX). R6 is the stack pointer.

POP             ST R2,Save2         ; needed by POP
                ST R1,Save1
                LD R1,BASE          ; contains -x3FFF
                ADD R1,R1,#-1       ; R1 contains -x4000
                ADD R2,R6,R1        ; check for stack underflow
                BRz fail_exit       ; branch if stack is empty
                LDR R0,R6,#0        ; POP
                ADD R6,R6,#1        ; increment stack pointer
                BRnzp success_exit
PUSH            ST R2,Save2         ; needed py PUSH
                ST R1,Save1
                LD R1,MAX           ; MAX contains -x3FFB
                ADD R2,R6,R1        ; check for stack overflow
                BRz fail_exit
                ADD R6,R6,#-1       ; decrement stack pointer
                STR R0,R6,#0        ; PUSH
success_exit    LD Rl,Save1         ; restore original
                LD R2,Save2         ; register values
                AND R5,R5,#0        ; R5 <-- success
                RET
fail_exit       LD R1,Save1         ; restore original
                LD R2,Save2         ; register values
                AND R5,R5,#0
                ADD R5,R5,#1        ; R5 <-- failure
                RET

BASE            .FILL XC001
MAX             .FILL XC005
Save1           .FILL xOOOO
Save2           .FILL xOOOO