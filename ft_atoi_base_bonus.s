	global ft_atoi_base

; rdi = str rsi = base

section .text
	ft_atoi_base :
		push rbx
		push r8
		xor rax, rax ; value
		xor rbx, rbx ; sign
		xor r8, r8 ; pointer
		
	
	whitespace : 
			cmp byte 
