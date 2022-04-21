; code at x3000
; memory location at x4000
foo_rv      .BLKW 1     ; foo return value
foo_ra      .BLKW 1     ; foo return address
foo_paramx  .BLKW 1     ; foo 'x' param
foo_paramy  .BLKW 1     ; foo 'y' param
foo_localz  .BLKW 1     ; foo 'z' local
bar_rv      .BLKW 1     ; bar return value
bar_ra      .BLKW 1     ; bar return address
bar_paramw  .BLKW 1     ; bar 'w' parameter

; + code can be marked as 'read only'
; + data persists for program life
; - still cannot handle recursion or parallel exe
; - consumes resource for inactive functions

; REAL SOLUTION: CREATING STACK
; stack grows down (conventionally)
; ADT : Lists, Queues, Heaps, Sets, Maps, etc.
; -1 to when adding to stack to keep top of stack at R6
; R6 keeps track of top of stack
; when POP stack..we dont remove, just ignore --> saves time
; PUSH, POP : GROWS DOWN IN MEMORY : FILO
PUSH Rx
    ADD R6, R6, #-1     ; decrement SP --> was x3FFF now x3FFE
    STR Rx, R6, #0      ; store value from Rx to R6 with 0 offset

POP Rx
    LDR Rx, R6, #0      ; load value
    ADD R6, R6, #1      ; Increment SP

