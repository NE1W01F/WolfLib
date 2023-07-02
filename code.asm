.code

PUBLIC GetPEB

GetPEB PROC
    MOV rax, gs:[00000060h] ; PEB
    RET
GetPEB ENDP

END
