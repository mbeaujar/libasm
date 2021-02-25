	global ft_list_sort

;rdi = t_list **list rsi = cmp()

section .text
	ft_list_sort :
		push r8
		push r12
		push r10
		mov r12, [rdi]
		mov rdi, r12
		xor rax, rax
		mov r8, [rdi + 8]

	while :
		cmp rdi, 0
		je return
		mov r12, [rdi]
		mov r10, [r8]
		push rdi
		push rsi
		mov rdi, r12
		mov rsi, r10
		call rsi
		pop rsi
		pop rdi
		cmp rax, 0
		jl reverse
		mov rdi, r8
		mov r8, [rdi + 8]
		jmp while 

	reverse :
		mov r12, [rdi]
		mov rdi, [r8]
		mov qword [r8], r12
		mov rdi, r8
		cmp rdi, 0
		je return
		mov r8, [rdi + 8]
		jmp while



	return :
		pop r10
		pop r12
		pop r8
		ret
		
	
