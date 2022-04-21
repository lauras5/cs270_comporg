            .ORG x3000
Main        JSR IntAdd      ; Call IntAdd Subroutine
            HALT            ;
;
Param1      .BLKW 1         ; Space to specify first param
Param2      .BLKW 1         ; Space to specify second param
Result      .BLKW 1         ; Space to store result
;
;
IntAdd      LD R0, Param1   ; Load first param
            LD R1, Param2   ; Load second param
            ADD R2, R1, R0  ; Output = Input1 + Input2
            ST R2, Result   ; Store result
            RET


; simple program adds 2 numbers