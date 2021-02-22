	global ft_atoi_base

; rdi = str rsi = base

section .text
	ft_atoi_base :
		push rbx
		push r8
		push r12
		xor rax, rax ; value
		xor rbx, rbx ; sign
		xor r8, r8 ; pointer base et base length
		xor r12, r12
		jmp base_loop
	
	inc : 
		inc r8

	base_loop :
		cmp byte [rsi + r8], 0 			; base == '\0'
		je check_base
		cmp		byte [rsi + r8], 32		; base ==  ' '
		je return_base
		cmp		byte [rsi + r8], 43		; base ==  '+'
		je return_base
		cmp		byte [rsi + r8], 45		; base ==  '-'
		je return_base
		cmp		byte [rsi + r8], 9		; base ==  '\t'
		je return_base
		cmp		byte [rsi + r8], 10		; base ==  '\n'
		je return_base
		cmp		byte [rsi + r8], 13		; base ==  '\r'
		je return_base
		cmp		byte [rsi + r8], 11		; base ==  '\v'
		je return_base
		cmp		byte [rsi + r8], 12		; base ==  '\f'
		je return_base
		mov r9b, byte [rsi + r8]
		mov r12, 0

	base_loop_double :
		cmp r12, r8
		je inc
		cmp byte [rsi + r12], r9b
		je return_base
		inc r12
		jmp base_loop_double
		

	check_base : 
		cmp r8, 1    ; check la taille de la base
		jle return_base
		mov r12, 0
		dec r12
		jmp whitespace

	return_base : 
		mov rax, 0 
		pop r8
		pop r12
		pop rbx
		ret 

	whitespace :
		inc r12
		cmp byte [rdi + r12], 32 ; skip ' '
		je whitespace
		cmp byte [rdi + r12], 9 ; skip '\t'
		je whitespace
		cmp byte [rdi + r12], 10 ; skip '\n'
		je whitespace
		cmp byte [rdi + r12], 11 ; skip '\v'
		je whitespace
		cmp byte [rdi + r12], 12 ; skip '\f'
		je whitespace
		cmp byte [rdi + r12], 13 ; skip '\r'
		je whitespace
		dec r12
		mov rbx, 1
		jmp sign

	sign_change : 
		neg rbx

	sign :
		inc r12 
		cmp byte [rdi + r12], 45
		je sign_change
		cmp byte [rdi + r12], 43
		je sign
		jmp main_loop

	inc_main : 
		inc r12

	main_loop : 
		cmp byte [rdi + r12], 0
		je set_sign
		xor r9, r9
		jmp is_base

	inc_base : 
		inc r9

	is_base : 
		mov r10b, byte [rdi + r9]
		cmp		r10b, 0	  ; fin de ma section
		je		set_sign 
		cmp		byte [rdi + r12], r10b
		jne		inc_base

	mul_value : 
		mul r8
		add rax, r9
		jmp inc_main

	set_sign :
		mov rax, rax
		cmp rbx, 1
		je return_value
		neg rax


	return_value : 
		pop r8
		pop r12
		pop rbx
		ret 







