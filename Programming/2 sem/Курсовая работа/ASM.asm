.586
.MODEL FLAT, STDCALL
PUBLIC fun1

_DATA SEGMENT
StrMas db 11 dup(?), 0
dec1 dd 10
_DATA ENDS

_TEXT SEGMENT
fun1 PROC par1: DWORD
    Lea ebx, StrMas
    mov ecx, 11
metka1: 
    mov BYTE PTR [ebx], ' '
    inc ebx
    loop metka1
    mov eax, par1
    push eax
    or eax, eax
    jns metka2
    neg eax
metka2:
    xor edx, edx
    div par1
    add dx, '0'
    dec ebx
    mov BYTE PTR [ebx], dl
    inc ecx
    or eax, eax
    jnz metka2
    pop eax
    or eax, eax
    jns metka3
    dec ebx
    mov BYTE PTR [ebx], ' '
    inc ecx
metka3:
    mov eax, ebx
    ret
fun1 ENDP
_TEXT ENDS
END