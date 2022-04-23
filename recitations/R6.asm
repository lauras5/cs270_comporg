;PACK:
;R0: 0x1234
;R1: 0x5678
;R0 = x3478

;1: use mask on R0 --> 0x0034
;2: left shift R0 by 8 bits --> 0x3400
;3: use mask on R1 --> 0x0078
;4: ADD R0, R0, R1

;UNPACK:
;R0: 0x3478
;R0 = 0x0034
;R1 = 0x0078

;1. use mask on R0, dont clear R0 because we still need it --> R0:0x3400
;2. shift R0 by 8 bits right --> 0x0034
;3. use mask --> R1: 0x0078

RightArithShift                      ; Result is Param1 >> Param2 with sign extension
                AND R0, R0, #0
                ADD R0, R0, #1       ; source mask set to 1
                AND R3, R3, #0
                ADD R3, R3, #1       ; destination mask
                AND R4, R4, #0       ; store result, set to 0
                LD R1, Param1        ; 34
                LD R2, Param2        ; param2 = 8 bits
                BRz skipAll          ; if set to 0, we can skip
maskLoop
                ADD R0, R0, R0
                ADD R2, R2, #-1      ; decrement because we break on zero
                BRp maskLoop
checkSet
                AND R2, R0, R1       ; check if bit is set
                BRz rightShift

                ADD R4, R3, R4       ; add to destination mask if set
rightShift
                ADD R3, R3, R3
                ADD R0, R0, R0
                BRp checkSet

                AND R2, R0, R1
                BRzp skipAll
fill
                ADD R4, R3, R4
                ADD R3, R3, R3       ; shift destination mask if negative
                BRp fill

                ADD R4, R3, R4
skipAll
                ST R4, Result

                RET

strcat_RA   .BLKW 1                 ; space for return address
strcat_dest .BLKW 1                 ; space for dest
strcat_src  .BLKW 1                 ; space for src

strcat      ST R7,strcat_RA         ; save return address
            ST R0,strcat_dest       ; save dest
            ST R1,strcat_src        ; save src

            ; fill in your code, ~5 lines of code
            ; HINT: call strlen and strcpy

            LD R0,strcat_dest       ; restore dest
            LD R7,strcat_RA         ; restore return address