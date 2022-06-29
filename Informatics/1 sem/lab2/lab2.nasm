;nasm -felf64 var1.asm && ld var1.o -o var1 && ./var1

section .data

section .bss
	num resd 1
	c resb 0 

global _start

section .text
 
output:	
	mov ecx, 32 
	xor r8, r8 
	mov ebx, 1 
	shl ebx, 31
	lp1:
	mov esi, eax
	and esi, ebx 
	shr esi, 31 
	add esi, 48 
	mov [edi], esi 
	shl eax, 1 
	inc edi 

	cmp ecx, 32
	jle if
	mov esi, 32
	mov [edi], esi
	inc edi
	inc r8

	if:
	inc r8 
	dec ecx
	cmp ecx, 0 
	jg lp1
	mov byte [edi], 10 
	inc r8

	mov eax, 1 
	mov edi, 1
	mov esi, c 
	mov rdx, r8 
	syscall 
ret

search_min:
	mov ebx, 0x3FF
	mov cl, 0
	mov r8w, 0x3FF
	lp2:
		mov edx, r12d
		and edx, ebx
		shr edx, cl
		shl ebx, 1
		cmp edx, r8d
		jg else
			mov r8d, edx
			mov r11b, cl
		else:
		inc cl
		cmp cl, 23
		jl lp2
ret

reverse:
	mov cl, 0
	mov ebx, 1
	mov r10d, 0
	lp3:
		mov r9d, r8d
		and r9d, ebx
		shr r9d, cl
		or r10d, r9d
		shl r10d, 1
		shl ebx, 1
		inc cl
		cmp cl, 9
		jl lp3
		mov r8d, r10d
ret

assembling:
	mov ebx, 0xFFFFFC00
	mov cl, r11b
	rol ebx, cl 
	and r12d, ebx
	shl r8d, cl 
	or r8d, r12d
ret


_start:
    mov rax, 0
    rdtsc
	mov r12d, eax
	mov edi, c
	call output

	call search_min

	call reverse

	call assembling

	mov eax, r8d
	mov edi, c
	call output
mov eax, 60
xor edi, edi
syscall

