; STEPS:
; 1. CALLER: push arguments (last to first)
; 2. CALLER: invoke subroutine (JSR)
; 3. CALLEE: allocate return address, push R7 & R5
; 4. CALLEE: set up new R5, allocate space for local var
; 5. CALLEE: execute function code
; 6. CALLEE: store result into return value slot
; 7. CALLEE: pop local vars, pop R5 & R7
; 8. CALLEE: return RET/JMP R7
; 9. CALLER: loads return value and pops args
; 10: CALLER: resumes computation

            .ORIG x3000
; caller
MAIN        LD R6, STACK            ; init stack pointer, load location of stack
            LD R0, B                ; load second operand       --> STEP 1
            PUSH R0                 ; PUSH second operand
            LD R1, A                ; load first operand
            PUSH R1                 ; PUSH first operand
            JSR FOO                 ; call function             --> STEP 2
            LDR R0, R6, #0          ; POP return value
            ADD R6, R6, #3          ; unwind stack
            ST R0, C                ; store result
            HALT                    ; end program

; callee
FOO
            ADD R6, R6, #1          ; allocate return value     --> STEP 3
            PUSH R7                 ; PUSH return address
            PUSH R5                 ; PUSH frame pointer (top)
            ADD R5, R6, #-1         ; FP = SP - 1               --> STEP 4.1

            ADD R6, R6, #-1         ; alloc local var           --> STEP 4.2
            LDR R2, R5, #4          ; load first operand into R2
            LDR R3, R5, #5          ; load second operand into R3
            ADD R4, R3, R2          ; add operands              --> STEP 5
            STR R4, R5, #0          ; store local variable into R5 (pointer)

            ; stack exit code
            STR R4, R5, #3          ; store return value --> STEP 6
            ADD R6, R5, #1          ; SP = FP + 1
            POP R5                  ; pop frame pointer
            POP R7                  ; pop return address
            RET                     ; return

A           .FILL #5                ; first operand
B           .FILL #20               ; second operand
C           .BLKW 1                 ; result
STACK       .FILL x4000             ; stack address