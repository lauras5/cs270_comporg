;
;       Algorithm to pop two values from the stack, multipy them,
;       and if their product is within the acceptable range, push
;       the result onto the stack. R6 is stack pointer.

OpMult          AND R3,R3,#0        ; R3 holds sign of multiplier
                JSR POP             ; get first source from stack
                ADD R5,R5,#0        ; test for successful POP
                BRp Exit            ; Failure
                ADD R1,R0,#0        ; make room for next POP
                JSR POP             ; get second src from stack
                ADD R5,R5,#0        ; test for successful POP
                BRp Restore1        ; Failure,restore first pop
                ADD R2,R0,#0        ; moves multiplier, test sign
                BRzp PosMultiplier
                ADD R3,R3,#1        ; sets flag, mult is negative
                NOT R2,R2
                ADD R2,R2,#1        ; R2 contains multiplier
PosMultiplier   AND R0,R0,#0        ; clear product register
                ADD R2,R2,#0
                BRz PushMult        ; Multiplier = 0
;
MultLoop        ADD R0,R0,R1        ; "multiply"
                ADD R2,R2,#-1       ; decrement counter
                BRp MultLoop
;
                JSR RangeCheck
                ADD R5,R5,#0        ; success / failure
                BRp Restore2
;
                ADD R3,R3,#0        ; test for neg multiplier
                BRz PushMult
                NOT R0,R0
                ADD R0,R0,#1
PushMult        JSR PUSH            ; push product on stack
                RET
Restore2        ADD R6,R6,#-1       ; adjust stack pointer
Restore1        ADD R6,R6,#-1       ; adjust stack pointer
Exit            RET
