;
;       Routine to pop the top two elements from the stack,
;       add them, and push the sum onto the stack. R6 is
;       the stack pointer.
;       - integers in the range - 999 to +999
;
OpAdd           JSR POP             ; Get first source operand
                ADD R5,R5,#0        ; test if pop was successful
                BRp Exit            ; branch if not successful
                ADD R1,R0,#0        ; Make room for second operand
                JSR POP             ; get second source operand
                ADD R5,R5,#0        ; check if pop was successful
                BRp Restore1        ; if not successful, put back first
                ADD R0,R0,R1        ; ADD
                JSR RangeCheck      ; check result size
                BRp Restore2        ; out of range resore both
                JSR PUSH            ; push sum on stack
                RET
Restore2        ADD R6,R6,#-1       ; decrement stack pointer
Restore1        ADD R6,R6,#-1       ; decrement stack pointer
Exit            RET